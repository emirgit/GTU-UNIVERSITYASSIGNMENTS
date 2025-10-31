import java.util.ArrayList;
import java.util.List;

//Dataset class that has add,remove,register,unregister, and notify methods
//It is implementation of basic pattern design
class Dataset implements Subject {

    //Two list to store references of Media object and Observers
    private List<Media> mediaList;
    private List<Observer> observers;

    public Dataset() {
        mediaList = new ArrayList<>();
        observers = new ArrayList<>();
    }

    //add method takes object and whether checks the object is Media or not
    //if it is Media, it add the object to the list and notify all observers
    //Otherwise, it warns the user
    public void add(Object obj) {
        if (obj instanceof Media) {
            Media media = (Media) obj;
            mediaList.add(media);
            notifyObservers(media, "add");
        }
        else {
            System.out.println("Warning: Object is not a Media instance.");
        }
    }

    //remove method takes object and whether checks the object is Media or not
    //if it is Media, it remove the object from the list and notify all observers
    //Otherwise, it warns the user.
    public void remove(Object obj) {
        if (obj instanceof Media) {
            Media media = (Media) obj;
            mediaList.remove(media);
            notifyObservers(media, "remove");
        }
        else {
            System.out.println("Warning: Object is not a Media instance.");
        }
    }

    //register methods take observer reference as parameter and add it to list of observer
    //and also it initialize the observer with media list

    public void register(Observer observer) {
        observer.setRegistered(true);
        observers.add(observer);
        // Update the observer with all elements with "add" mode
        for (Media media : mediaList) {
            if ((media instanceof Playable && observer instanceof Player)
                    || (media instanceof Non_playable && observer instanceof Viewer)) {
                observer.update(media, "add");
            }
        }
    }

    /*
    public void register(Observer observer) {
        observer.setRegistered(true);
        observers.add(observer);
        // Update the observer with all elements with "add" mode
        for (Media media : mediaList) {
            observer.update(media, "add");
        }
    }

     */

    //register methods take observer reference as parameter and remove it from list of observer
    public void unregister(Observer observer) {
        observer.setRegistered(false);
        observers.remove(observer);
        observer.clear();
    }

    //notifyObservers method notifys the observer of dataset about the changing in the dataset


    /*
    public void notifyObservers(Media media, String event) {
        for (Observer observer : observers) {
            observer.update(media, event);
        }
    }
     */



    public void notifyObservers(Media media, String event) {
        for (Observer observer : observers) {
            if ((media instanceof Playable && observer instanceof Player)
                || (media instanceof Non_playable && observer instanceof Viewer)) {
                observer.update(media, event);
            }

        }


    }

}




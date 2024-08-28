import java.util.ArrayList;
import java.util.List;

//Viewer class is a Observer of the dataset
//it observes the change of the dataset and apply changes
class Viewer implements Observer {
    //the viewList is a list to store the Non_playable object
    private List<Non_playable> viewList;
    //currentIndex is a integer to keep track of current playing object
    private int currentIndex;
    private boolean isRegistered;

    //constructor to initiliazie the viewer object
    public Viewer() {
        currentIndex = 0;
        isRegistered = false;
        viewList = new ArrayList<>();
    }

    //Update is a method takes 2 object as parameters
    //first object is a media object to put list
    //second is event that is either "add" or "remove"
    //the method whether check the media is Non_playable or not
    //if it is, it apply the event to the list

    /*
    @Override
    public void update(Media media, String event) {

        if (media instanceof Non_playable) {
            if ("add".equals(event)) {
                viewList.add((Non_playable) media);
            }
            else if ("remove".equals(event)) {
                viewList.remove((Non_playable) media);
                if (currentIndex >= viewList.size()) {
                    currentIndex = 0; // Reset currentIndex if out of bounds
                }
            }
        }
    }
     */


    @Override
    public void update(Media media, String event) {

        if ("add".equals(event)) {
            viewList.add((Non_playable) media);
        }
        else if ("remove".equals(event)) {
            viewList.remove((Non_playable) media);
            if (currentIndex >= viewList.size()) {
                currentIndex = 0; // Reset currentIndex if out of bounds
            }
        }
    }





    //showList show the info of viewlist
    public void showList() {
        if (!isRegistered)
            throw new IllegalStateException("The viewer have not registered to Dataset");

        for (Non_playable item : viewList) {
            item.info();
        }
    }
    //currently_playing() return the current playing object
    Non_playable currently_viewing() {


        if (viewList.isEmpty() || !isRegistered) {
            throw new IllegalStateException("No items to view.");
        }
        return viewList.get(currentIndex);
    }

    //it passes to next type of Non_playable
    public void next(String type) {
        if (!isRegistered)
            throw new IllegalStateException("The viewer have not registered to Dataset");

        currentIndex = findIndex(type, currentIndex, 1);
    }
    //it passes to previous type of Non_playable
    public void previous(String type) {
        if (!isRegistered)
            throw new IllegalStateException("The viewer have not registered to Dataset");

        currentIndex = findIndex(type, currentIndex, -1);
    }

    //it finds the next or previous type of object
    //the algorithm of the method is to prevent of object passing the size of viewList and
    //being less than 0
    //so, I found this index = (index + step + viewList.size()) % viewList.size();
    //if step is -1 and index 0 it will be (-1 + size) % size will give size - 1 that is last element of list
    //if step is 1 and index is size - 1 it will be (size -1 + 1) % size will give 0 that is first element
    //if there is no element in list it will find the current Index that is a type of expection
    //and it will throw IllegalStateException
    private int findIndex(String type, int currentIndex, int step) {
        int index = currentIndex;
        while (true) {
            index = (index + step + viewList.size()) % viewList.size();
            Media item = (Media) viewList.get(index);
            if ((type.equals("text") && item instanceof Text) ||
                    (type.equals("image") && item instanceof Image)) {
                return index;
            }
            if (index == currentIndex) {
                break;
            }
        }
        throw new IllegalStateException("No more items of type " + type + ".");
    }

    //setter for register
    public void setRegistered(boolean registered) {
        isRegistered = registered;
    }


    //cleaning the list
    public void clear(){
        viewList.clear();
        currentIndex = 0;
    }
}


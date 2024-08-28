import java.util.ArrayList;
import java.util.List;

//Player class is a Observer of the dataset
//it observes the change of the dataset and apply changes
class Player implements Observer {
    //the playList is a list to store the Playable object
    private List<Playable> playList;
    //currentIndex is a integer to keep track of current playing object
    private int currentIndex;
    private boolean isRegistered;

    //constructor to initiliazie the player object
    public Player() {
        currentIndex = 0;
        isRegistered = false;
        playList = new ArrayList<>();
    }

    //Update is a method takes 2 object as parameters
    //first object is a media object to put list
    //second is event that is either "add" or "remove"
    //the method whether check the media is playable or not
    //if it is, it apply the event to the list

    /*
    @Override
    public void update(Media media, String event) {
        if (media instanceof Playable) {
            if ("add".equals(event)) {
                playList.add((Playable) media);

            }
            else if ("remove".equals(event)) {
                playList.remove((Playable) media);
                if (currentIndex >= playList.size()) {
                    currentIndex = 0; // Reset currentIndex if out of bounds
                }
            }
        }

    }
     */


    public void update(Media media, String event) {
        if ("add".equals(event)) {
            playList.add((Playable) media);

        }
        else if ("remove".equals(event)) {
            playList.remove((Playable) media);
            if (currentIndex >= playList.size()) {
                currentIndex = 0; // Reset currentIndex if out of bounds
            }
        }

    }




    //showList show the info of playlist
    void showList() {
        if (!isRegistered)
            throw new IllegalStateException("The player have not registered to Dataset");

        for (Playable item : playList) {
            item.info();
        }
    }

    //currently_playing() return the current playing object
    Playable currently_playing() {
        if (playList.isEmpty() || !isRegistered) {
            throw new IllegalStateException("No items to play.");
        }
        return playList.get(currentIndex);
    }

    //it passes to next type of playable
    public void next(String type) {
        if (!isRegistered)
            throw new IllegalStateException("The player have not registered to Dataset");

        currentIndex = findIndex(type, currentIndex, 1);
    }

    //it passes to previous type of playable
    public void previous(String type) {
        if (!isRegistered)
            throw new IllegalStateException("The player have not registered to Dataset");

        currentIndex = findIndex(type, currentIndex, -1);
    }

    //it finds the next or previous type of object
    //the algorithm of the method is to prevent of object passing the size of platlist and
    //being less than 0
    //so, I found this index = (index + step + playList.size()) % playList.size();
    //if step is -1 and index 0 it will be (-1 + size) % size will give size - 1 that is last element of list
    //if step is 1 and index is size - 1 it will be (size -1 + 1) % size will give 0 that is first element
    //if there is no element in list it will find the current Index that is a type of expection
    //and it will throw IllegalStateException
    private int findIndex(String type, int currentIndex, int step) {
        int index = currentIndex;

        while (true) {
            index = (index + step + playList.size()) % playList.size();
            Playable item = playList.get(index);
            if ((type.equals("audio") && item instanceof Audio) ||
                    (type.equals("video") && item instanceof Video)) {
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
        playList.clear();
        currentIndex = 0;
    }
}

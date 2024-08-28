//Observer interface for observers of the dataset
interface Observer {
    void update(Media media, String event);
    void setRegistered(boolean registered);
    void clear();

    void next(String type);

    //it passes to previous type of playable
    void previous(String type);
}

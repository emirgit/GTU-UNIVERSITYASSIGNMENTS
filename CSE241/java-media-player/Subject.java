public interface Subject {
    void add(Object obj);
    void remove(Object obj);

    void register(Observer observer);
    void unregister(Observer observer);

    void notifyObservers(Media media, String event);
}

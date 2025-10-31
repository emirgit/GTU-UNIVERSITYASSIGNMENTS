// Audio class inherited from Media and implements Playable and Non_visual interfaces
public class Audio extends Media implements Playable, Non_visual {

    //the field that stores the duration info
    private String duration;

    //3 parameter constructor
    Audio(String name, String duration, String info) {
        super(name, info);
        this.duration = duration;
    }

    //info method to print the info of the object, that is from interfaces
    @Override
    public void info(){
        System.out.println(getName() + " : "  + getInfo() + " - " + duration);
    }

    //play method to print the duration info of object, that is from Playable interface
    @Override
    public void play(){
        System.out.println("Duration : " + duration);
    }

    //getter and setters
    public String getDuration() {
        return duration;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }
}

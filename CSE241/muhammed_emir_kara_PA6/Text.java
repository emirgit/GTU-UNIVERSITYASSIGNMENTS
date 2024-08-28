// Video class inherited from Media and implements Non_playable and Non_visual interfaces

public class Text extends Media implements Non_playable, Non_visual {


    //1 parameter constructor
    public Text(String name) {
        super(name, "Null");
    }

    //2 parameter constructor
    public Text(String name, String info) {
        super(name, info);
        setName(name);
    }

    //info method to print the info of the object, that is from interfaces
    @Override
    public void info() {
        System.out.println(getName() + " : " + getInfo());
    }

}


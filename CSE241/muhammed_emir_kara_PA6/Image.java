// Video class inherited from Media and implements Non_playable and Visual interfaces
public class Image extends Media implements Non_playable, Visual{

    //the field that stores the dimension info

    private String dimension;
    //3 parameter constructor
    Image(String name, String dimension, String info) {
        super(name, info);
        this.dimension = dimension;
    }

    //info method to print the info of the object, that is from interfaces
    @Override
    public void info(){
        System.out.println(getName() + " : " + getInfo());
    }
    //show method to print the dimension of the objec
    public void show(){
        System.out.println("Dimension : " + dimension);
    }

    //getters and setters
    public String getDimension() {
        return dimension;
    }

    public void setDimension(String dimension) {
        this.dimension = dimension;
    }
}

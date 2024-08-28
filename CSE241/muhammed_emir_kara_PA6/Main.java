

public class Main {


    public static void main(String args[]) {
        Dataset ds = new Dataset();

        Player p1 = new Player();
        Player p2 = new Player();
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();

        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);

        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Image("imagename2", "dimension info2", "other info2"));
        ds.add(new Image("imagename3", "dimension info3", "other info3"));
        ds.add(new Image("imagename4", "dimension info4", "other info4"));
        ds.add(new Image("imagename5", "dimension info5", "other info5"));
        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname2", "duration2", "other info2"));
        ds.add(new Audio("audioname3", "duration3", "other info3"));
        ds.add(new Video("videoname1", "duration1", "other info1"));
        ds.add(new Video("videoname2", "duration2", "other info2"));
        ds.add(new Video("videoname3", "duration3", "other info3"));
        ds.add(new Text("textname1", "other info1"));
        ds.add(new Text("textname2", "other info2"));
        ds.add(new Text("textname3", "other info3"));


        Playable po = p1.currently_playing();
        po.info();
        ds.remove(po);
        p1.next("video");
        System.out.println();
        Playable pov = p1.currently_playing();
        pov.info();
        ds.remove(pov);
        System.out.println();

        Non_playable np = v1.currently_viewing();
        np.info();
        System.out.println();

        p1.showList();
        System.out.println();
        v1.showList();

    }
}

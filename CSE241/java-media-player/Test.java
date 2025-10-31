import java.util.ArrayList;
import java.util.List;

class Test {

    public static void main(String args[]) {
        Dataset ds = new Dataset();

        List<Player> players = new ArrayList<>();
        List<Viewer> viewers = new ArrayList<>();

        for (int i = 1; i <= 5; i++) {
            Player p = new Player();
            Viewer v = new Viewer();
            players.add(p);
            viewers.add(v);
            ds.register(p);
            ds.register(v);
        }

        for (int i = 1; i <= 10; i++) {
            ds.add(new Image("imagename" + i, "dimension info" + i, "other info" + i));
            ds.add(new Audio("audioname" + i, "duration" + i, "other info" + i));
            ds.add(new Video("videoname" + i, "duration" + i, "other info" + i));
            ds.add(new Text("textname" + i, "other info" + i));
        }

        for (Player player : players) {
            Playable po = player.currently_playing();
            if (po != null) {
                po.info();
                ds.remove(po);
            }
            System.out.println();
        }

        for (Viewer viewer : viewers) {
            Non_playable np = viewer.currently_viewing();
            if (np != null) {
                np.info();
            }
            System.out.println();
        }

        for (Player player : players) {
            player.showList();
            System.out.println();
        }

        for (Viewer viewer : viewers) {
            viewer.showList();
            System.out.println();
        }

        //Testing for no item exception
        try {
            while(true){
                players.get(0).next("video");
                Playable po = players.get(0).currently_playing();
                po.info();
                ds.remove(po);
            }
        }
        catch (IllegalStateException e){
            System.out.println("IllegalStateException found");
            //e.printStackTrace();
        }
        System.out.println();
        viewers.get(0).next("text");
        viewers.get(1).currently_viewing().info();
        viewers.get(0).currently_viewing().info();
        System.out.println();

        for (int i = 0; i < 12; i++){
            viewers.get(2).next("text");
            viewers.get(2).currently_viewing().info();
        }
        System.out.println();
        for (int i = 0; i < 12; i++){
            viewers.get(2).previous("image");
            viewers.get(2).currently_viewing().info();
        }

        System.out.println();
        viewers.get(3).previous("image");
        viewers.get(3).currently_viewing().info();
        System.out.println();
        ds.add(new Image("imagename" + 11, "dimension info" + 11, "other info" + 11));
        viewers.get(3).next("image");
        viewers.get(3).currently_viewing().info();
        System.out.println();

        System.out.println("Testing register and unregister");
        try {
            viewers.get(3).next("image");
            ds.unregister(viewers.get(3));
            viewers.get(3).currently_viewing().info();
        }
        catch (IllegalStateException e){
            System.out.println("IllegalStateException found");
            //e.printStackTrace();
        }
        System.out.println("After registering again");
        ds.register(viewers.get(3));
        viewers.get(3).currently_viewing().info();

    }
}

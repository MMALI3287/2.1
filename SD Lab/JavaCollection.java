import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class JavaCollection {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<String> ll = new LinkedList<String>();
        ArrayList<String> list1 = new ArrayList<String>();
        list1.add("Naushin");
        list1.add("Nafisa");
        list1.add("Tabia");
        list1.add("Mifta");
        list1.add("Misba");
        for (int i = 0; i < list1.size(); i++) {
            System.out.println(list1.get(i));
        }
        for (int i = 3; i < 4; i++) {
            System.out.println("Enter new item: ");
            String item = sc.nextLine();
            list1.set(i, item);
        }
        list1.remove(1);
        list1.remove(0);
        list1.remove(2);
        System.out.println(list1);
        Iterator<String> itr = list1.iterator(); // Iterator is used to traverse the collection
        while (itr.hasNext()) {
            System.out.println(itr.next());
        }
    }
}
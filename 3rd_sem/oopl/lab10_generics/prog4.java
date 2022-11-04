import java.util.*; 
class prog4 {
    public static void display(Collection<?> c) {
        for (Object o : c) {
            System.out.println(o);
        }
    }
   
    public static void main(String[] args) {
     Collection<String> c1 = new ArrayList<>();
     c1.add("ArrayList");
     display(c1);
     Collection<String> c2 = new LinkedList<>();
     c2.add("LinkedList");
     display(c2);
     Collection<String> c3 = new Stack<>();
     c3.add("Stack");
     display(c3);
     
    }
   }
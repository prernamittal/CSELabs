import java.util.*;
public class extra2 {
    public static <T extends Comparable<T>> T maximum(T x, T y, T z) {
      T max = x; 
  
      if (y.compareTo(max) > 0)
        max = y; 
  
      if (z.compareTo(max) > 0)
        max = z; 
  
      return max; 
    } 
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int choice;
        do{
        System.out.printf("\n\n1.integers\n2.String\nEnter choice: ");
        choice= sc.nextInt();
        switch(choice)
        {
            case 1: 
            System.out.println("Enter 3 integers:");
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            System.out.printf("Maximum is: " + maximum(x,y,z)+"\n");
            break;
            case 2:
            System.out.println("Enter 3 strings:");
            String a = sc.next();
            String b = sc.next();
            String c = sc.next();
            System.out.printf("Maximum is: " +maximum(a,b,c)+"\n");
            break;
        }
    }while(choice!=3);
    }
}
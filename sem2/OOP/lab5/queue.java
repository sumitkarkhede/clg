// Q.1)Image a queue of people standing at the bus stand to buy tickets .whenever a person buys a ticket,he leaves
// the queue and all the remaining people take one step forward.any new person joins the queue at the
// back.implement the above queue for integer in the folowing mannerdefine an interface named QueueImpl that
// will have method to insert into the queue ,delete from the queue and display the integer currently present int the
// queue.let a class calleld QueueDemo implement the interface .Make your own provisions for exception handaling
// in case of overflow and underflow condation use an array (with maximum size 10) to hiuse the queue. Write a
// single main program ti demonstrate the insert ,delete and display operations as well as the Exception handaling
// in case of overflow and underflow condation.

import java.util.Scanner;
interface QueueImpl {
    void insert(int value) throws Exception;

    int delete() throws Exception;

    void display();
}

class QueueDemo implements QueueImpl {
    private int[] queue;
    private int front, rear, maxSize;

    public QueueDemo(int size) {
        queue = new int[size];
        front = 0;
        rear = -1;
        maxSize = size;
    }

    public void insert(int value) throws Exception {
        if (rear == maxSize - 1) {
            throw new Exception("Queue Overflow");
        }
        queue[++rear] = value;
    }

    public int delete() throws Exception {
        if (front > rear) {
            throw new Exception("Queue Underflow");
        }
        return queue[front++];
    }

    public void display() {
        if (front > rear) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.print("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            System.out.print(queue[i] + " ");
        }
        System.out.println();
    }
}

public class queue {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        QueueDemo queue = new QueueDemo(10);

        while (true) {
            System.out.println("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
            System.out.print("Choose an operation: ");
            int choice = sc.nextInt();

            try {
                switch (choice) {
                    case 1:
                        System.out.print("Enter value to insert: ");
                        int value = sc.nextInt();
                        queue.insert(value);
                        System.out.println("Inserted " + value);
                        break;
                    case 2:
                        int deletedValue = queue.delete();
                        System.out.println("Deleted " + deletedValue);
                        break;
                    case 3:
                        queue.display();
                        break;
                    case 4:
                        System.out.println("Exiting...");
                        sc.close();
                        return;
                    default:
                        System.out.println("Invalid choice\n please try again.");
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
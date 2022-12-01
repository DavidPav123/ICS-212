import java.util.Scanner;

class homework9 {
    private native static int is_multiple4(int num);

    static {
        System.loadLibrary("homework9");
    }

    public static void main(String args[]) {
        print_table(user_interface());
    }

    static int user_interface() {
        int input;
        try (Scanner myObj = new Scanner(System.in)) {
            System.out.println(
                    "This program will ask for a maximum poitive integer\n It will then print out all of the numbers from 0 up to and including the input number\n It will also print if each number is a multiple of 4.\n\nEnter maximum number to show: ");

            while (true) {
                String inputStr = myObj.nextLine();
                try {
                    input = Integer.parseInt(inputStr);
                    if (input < 0) {
                        System.out.println(
                                "Input was not positive. Please enter a positive Integer.\n\nEnter maximum number to show: ");
                    } else {
                        return input;
                    }
                } catch (Exception NumberFormatException) {
                    System.out.println(
                            "Input was not a number. Please enter a positive Integer.\n\nEnter maximum number to show: ");
                }
            }
        }
    }

    static void print_table(int maxNum) {
        int i;

        System.out.printf("%10s %s\n", "Number", "Multiple of 4?");

        for (i = 0; i <= maxNum; i++) {
            System.out.printf("%10d %s\n", i, is_multiple4(i) == 1 ? "Yes" : "No");
        }
    }
}
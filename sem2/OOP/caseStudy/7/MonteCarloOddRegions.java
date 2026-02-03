public class MonteCarloOddRegions {
    public static void main(String[] args) {
        int trials = 1000000;
        int oddCount = 0;

        for (int i = 0; i < trials; i++) {
            // Generate random point in square [-1, 1] x [-1, 1]
            double x = Math.random() * 2 - 1; // x in [-1, 1]
            double y = Math.random() * 2 - 1;// y in [-1, 1]

            // Check Region 1
            if (x < 0) {
                oddCount++;
            }
            // Right half
            else {
                if (y >= 0 && y <= -x + 1) {
                    // Region 3 (odd)
                    oddCount++;
                }
            }
        }

        double probability = (double) oddCount / trials;
        System.out.println("Estimated probability of landing in an odd-numbered region: " + probability);
    }
}
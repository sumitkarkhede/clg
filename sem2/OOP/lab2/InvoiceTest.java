/*Q2.) Create a class called invoice that hardware store might use to represent an invoice for an item sold at the
store. An invoice should include four pieces of information as instance variable

 a part number(type string)
 a part description(type string)
 a quantity of the item being purchased(type int)
 a price per item(double)

Your class should have a constructor that initialization the four instance variable . Provide a set and a get method
for each instance variable . In addition provide method named getInvoiceAmount that calculate the invoice
amount(i.e. multiplies the quantity per item ), then return the amount as a double value.If the quantity is not
positive it should be set to 0. If the price per item is not positive it should be set to 0.0. Write test application
named invoice test that demonstration class invoice capabilities.
*/
class Invoice {

    // Instance variables (default access, no private)
    String partNumber;
    String partDescription;
    int quantity;
    double pricePerItem;

    // Constructor
    Invoice(String partNumber, String partDescription, int quantity, double pricePerItem) {
        this.partNumber = partNumber;
        this.partDescription = partDescription;

        if (quantity > 0)
            this.quantity = quantity;
        else
            this.quantity = 0;

        if (pricePerItem > 0)
            this.pricePerItem = pricePerItem;
        else
            this.pricePerItem = 0.0;
    }

    // Set methods
    void setPartNumber(String partNumber) {
        this.partNumber = partNumber;
    }

    void setPartDescription(String partDescription) {
        this.partDescription = partDescription;
    }

    void setQuantity(int quantity) {
        if (quantity > 0)
            this.quantity = quantity;
        else
            this.quantity = 0;
    }

    void setPricePerItem(double pricePerItem) {
        if (pricePerItem > 0)
            this.pricePerItem = pricePerItem;
        else
            this.pricePerItem = 0.0;
    }

    // Get methods are used to access instance variables 
    //in case of default access modifier they are not accessible outside the package because of encapsulation
    String getPartNumber() {
        return partNumber;
    }

    String getPartDescription() {
        return partDescription;
    }

    int getQuantity() {
        return quantity;
    }

    double getPricePerItem() {
        return pricePerItem;
    }

    // Calculate invoice amount
    double getInvoiceAmount() {
        return quantity * pricePerItem;
    }
}

public class InvoiceTest {

    public static void main(String[] args) {

        // Create Invoice object
        Invoice invoice = new Invoice("P101", "Hard Disk", 3, 4500.50);

        // Display invoice details
        System.out.println("Part Number: " + invoice.getPartNumber());
        System.out.println("Part Description: " + invoice.getPartDescription());
        System.out.println("Quantity: " + invoice.getQuantity());
        System.out.println("Price per Item: " + invoice.getPricePerItem());
        System.out.println("Invoice Amount: " + invoice.getInvoiceAmount());

        // Test validation
        invoice.setQuantity(-5);
        invoice.setPricePerItem(-200);

        System.out.println("\nAfter invalid values:");
        System.out.println("Quantity: " + invoice.getQuantity());
        System.out.println("Price per Item: " + invoice.getPricePerItem());
        System.out.println("Invoice Amount: " + invoice.getInvoiceAmount());
    }
}

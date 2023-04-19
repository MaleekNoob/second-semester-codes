#include <iostream>
using namespace std;

void validation(int& n) {
    while(n < 0) {
        cout << endl << "Please enter a positive number: ";
        cin >> n;
    }
}

class Product {
    string name;
    int quantity;
    double price;
    float discount, tax, promotion;
    bool isDiscount, isTax, isPromotion;

    public:
    Product(string n = "", int q = 0, double p = 0, float d = 0, float t = 0, float pr = 0/*, bool isD = false, bool isT = false, bool isP = false*/) {
        name = n;
        quantity = q;
        price = p;
        discount = d;
        tax = t;
        promotion = pr;
    }

    void setName(string n) {
        this->name = n;
    }

    void setQuantity(int q) {
        this->quantity = q;
    }

    void setPrice(double p) {
        this->price = p;
    }

    void setDiscount(float d) {
        isDiscount = true;
        discount = d;
        if (price == 0) 
            cout << endl << "WARNING: Price is zero";
        price -= price * (discount/100);
    }

    void setTax(float t) {
        isTax = true;
        tax = t;
        if (price == 0) {
            cout << endl << "WARNING: Price is zero";
        }
        price += price * (tax/100);
    }

    void setPromotion(float p) {
        isPromotion = true;
        promotion = p;
        if (price == 0)
            cout << endl << "WARNING: Price is zero";
        price -= price * (promotion/100);
    }

    int getQuantity() {
        return quantity;
    }

    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    float getDiscount() {
        return discount;
    }

    float getTax() {
        return tax;
    }

    float getPromotion() {
        return promotion;
    }

    void display() {
        cout << endl << "Name of the product: " << name;
        cout << endl << "Quantity of the product: " << quantity;
    }
};

class InventoryManagementModule {
    Product* p;
    int numberOfProducts;

    void addProduct(string n, int q) {
        int size = numberOfProducts + 1;
        Product* temp = new Product[size];
        for (int i = 0; i < numberOfProducts; i++) {
            temp[i] = p[i];
        }
        numberOfProducts = size;
        delete[] p;
        p = temp;
        p[numberOfProducts - 1] = Product(n, q);
    }

public:
    InventoryManagementModule() {
        p = nullptr;
        numberOfProducts = 0;
    }

    InventoryManagementModule(InventoryManagementModule& i) {
        p = new Product[i.numberOfProducts];
        for (int j = 0; j < i.numberOfProducts; j++) {
            p[j] = i.p[j];
        }
        numberOfProducts = i.numberOfProducts;
    }

	void productOrdering() {

        cout << endl << "**************Product Ordering Utility***************";
        string name;
        int quantity;
        int choice = 0;
        while(choice != 3) {
            cout << "\nDo you want to order new Product or modify order exsisting one?\n1-Order new Product\n2-Modify exsisting Product\n3-Back\nSelect option: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                if (numberOfProducts < 100) {
                    cout << endl << "******************Adding new Product********************\nEnter the name of the Product: ";
                    cin >> name;
                    cout << "\nEnter the Quantity: ";
                    cin >> quantity;
                    addProduct(name, quantity);
                }
                else {
                    cout << "\nInventory level reached it's maximum.";
                }
                break;
            }

            case 2:
            {
                int choice = 0;
                cout << "******************Modifying exsisting Product********************";
                cout << "\nEnter name of exsisting product: ";
                cin >> name;
                for (int i = 0; i < numberOfProducts; i++) {
                    if (name == p[i].getName()) {
                        while(choice != 4) {
                            cout << "\n1-Change name of the Product\n2-Add quantity of the product\n3-Change name as well as add more quantity\n4-Back\nSelect option: ";
                            cin >> choice;
                            switch (choice)
                            {
                            case 1:
                                cout << "\nEnter new name: ";
                                cin >> name;
                                p[i].setName(name);
                                break;

                            case 2:
                                cout << "\nEnter quantity to be added: ";
                                cin >> quantity;
                                p[i].setQuantity(quantity + p[i].getQuantity());
                                break;

                            case 3:
                                cout << "\nEnter new name: ";
                                cin >> name;
                                p[i].setName(name);
                                cout << "\nEnter quantity to be added: ";
                                cin >> quantity;
                                p[i].setQuantity(quantity + p[i].getQuantity());
                                break;

                            case 4:
                                break;
                            
                            default:
                                cout << "\nInvalid input";
                                break;
                            }
                        }

                        break;
                    }
                    if (i == numberOfProducts - 1)
                        cout << "\nProduct not found";
                }

                break;
            }
            
            default:
                break;
            }
        }
    }

	void productsTake() {
        cout << endl << "**********************Product Taking Utility*************************";
        string name;
        int quantity;
        int choice;
        while(choice != 3) {
            cout << "\nEnter the name of the Product you want to take: ";
            cin >> name;
            cout << "\nEnter quantity: ";
            cin >> quantity;
            for (int i = 0; i < numberOfProducts; i++) {
                if (name == p[i].getName()) {
                    while (p[i].getQuantity() < quantity){
                        cout << "ERROR! Entered quantity is greater than availble. Do you want to\n1-Order more\n2-Re-Enter quantity\n3-Back\nSelect option: ";
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                            productOrdering();
                            break;
                        
                        case 2:
                            cout << "Enter Quantity: ";
                            cin >> quantity;
                            break;

                        default:
                            break;
                        }
                    }

                    p[i].setQuantity(p[i].getQuantity() - quantity);
                }
            }
        }
	}

	void priceManagement() {
		cout << "\n*******************Price Management Utility*******************";
        string name;
        double price;
        int choice;
        cout << "\nEnter the name of the Product you want to change price of: ";
        cin >> name;
        for (int i = 0; i < numberOfProducts; i++) {
            if (name == p[i].getName()) {
                cout << "\nEnter new price: ";
                cin >> price;
                p[i].setPrice(price);
            }
            if (i == numberOfProducts - 1)
                cout << "\nProduct not found";
        }
	}

};

class POSModule {
public:
	void addToCart() {
		//add items to the cart for customer.
	}

	void applyDiscount() {
		//apply discounts based on promotions or other factors.
	}

	void issueRefunds() {
		//refund on customers order and updates inventory levels.
	}

};

class ReportingModule {
public:
	void salesReport() {
		//generate reports based on sales
	}

	void inventoryReport() {
		//genrate reports based on inventory levels
	}

	void profitReports() {
		//generate reports based on profits
	}

};

class Manager: public InventoryManagementModule, public ReportingModule {
    private:


    public:
        Manager() {}

};

class Salesman: public POSModule, public ReportingModule {
    private:


    public:
        Salesman() {}
};

int main() {

    int choice;
    while(choice != 3) {
        cout << "Enter choice (1-Manager, 2-Salesman, 3-Exit): ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                int choice = 0;
                Manager* m = new Manager();
                while(choice != 3) {
                    cout << endl << "*********MANAGER DASHBOARD**********";
                    cout << endl << "1-Inventroy Management Module\n2-Report Module\n3-Back\nSelect option: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        while(choice != 4) {
                            cout << endl << "**************INVENTROY MANAGEMENT MODULE*****************";
                            cout << endl << "1-Order Product\n2-Take Product\n3-Manage Price\n4-Back\nSelect option: ";
                            cin >> choice;
                            switch (choice)
                            {
                            case 1:
                                m->productOrdering();
                                break;

                            case 2:
                                m->productsTake();
                                break;

                            case 3:
                                m->priceManagement();
                                break;

                            case 4:
                                break;
                            
                            default:
                                cout << "Invalid Input";
                                break;
                            }
                        }
                        break;

                    case 3:
                        break;
                    
                    default:
                        cout << "\nInvalid Input";
                        break;
                    }

                    // break;
                }

                break;
            }
            
            case 2:
                cout << "*********SALESMAN DASHBOARD**********";
                break;

            case 3:
                cout << "********You terminated**********";
                break;

            default:
                cout << "Invalid input!";
                break;
        }
    }

    return 0;
}
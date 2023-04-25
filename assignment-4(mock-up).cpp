#include <iostream>
using namespace std;

void validation(int& n) {
    while(n < 0) {
        cout << endl << "Please enter a positive number: ";
        cin >> n;
    }
}

class Manager;

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

    friend ostream& operator<<(ostream& out, Product& p);
};

ostream& operator<<(ostream& out, Product& p) {
    out << endl << "Name of the product: " << p.name;
    out << endl << "Quantity of the product: " << p.quantity;
    out << endl << "Price of the product: " << p.price;
    if (p.isDiscount) {
        out << endl << "Discount on the product: " << p.discount;
    }
    if (p.isTax) {
        out << endl << "Tax on the product: " << p.tax;
    }
    if (p.isPromotion) {
        out << endl << "Promotion on the product: " << p.promotion;
    }
    return out;
}

class Cart {
    Product* p;
    int numberOfProducts;
    double total;

    public:
    Cart(Product* p = nullptr, int n = 0, double t = 0) {
        this->p = p;
        numberOfProducts = n;
        total = t;
    }

    void setProduct(Product* p) {
        this->p = p;
    }

    void setNumberOfProducts(int n) {
        this->numberOfProducts = n;
    }

    void setTotal(double t) {
        this->total = t;
    }

    Product* getProduct() {
        return p;
    }

    int getNumberOfProducts() {
        return numberOfProducts;
    }

    double getTotal() {
        return total;
    }

    void addProduct(string name, int quantity, double price) {
        int size = numberOfProducts + 1;
        Product* temp = new Product[size];
        for (int i = 0; i < numberOfProducts; i++) {
            temp[i] = p[i];
        }
        numberOfProducts = size;
        delete[] p;
        p = temp;
        p[numberOfProducts - 1] = Product(name, quantity, price);
    }

    void display() {
        for (int i = 0; i < numberOfProducts; i++) {
            cout << endl << "Product " << i + 1 << ": ";
            cout << p[i];
        }
        cout << endl << "Number of products in the cart: " << numberOfProducts;
        cout << endl << "Total bill: " << total;
    }
};

class Customer {
    Cart* c;
    double balance;

    public:
    Customer(Cart* c = nullptr, double b = 0) {
        this->c = c;
        balance = b;
    }

    void setCart(Cart* c) {
        this->c = c;
    }

    void setBalance(double b) {
        this->balance = b;
    }

    Cart* getCart() {
        return c;
    }

    double getBalance() {
        return balance;
    }

    void display() {
        cout << endl << "Balance: " << balance;
        cout << endl << "Cart: ";
        c->display();
    }
};

class InventoryManagementModule {
    protected:
    Product* p;
    int numberOfProducts;

    void addProduct(string n, int q, double pr) {
        int size = numberOfProducts + 1;
        Product* temp = new Product[size];
        for (int i = 0; i < numberOfProducts; i++) {
            temp[i] = p[i];
        }
        numberOfProducts = size;
        delete[] p;
        p = temp;
        p[numberOfProducts - 1] = Product(n, q, pr);
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
        double price;
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
                    cout << "\nEnter the Price: ";
                    cin >> price;
                    addProduct(name, quantity, price);
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

    int getNumberOfProducts() {
        return numberOfProducts;
    }

    Product* getProducts() {
        return p;
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

class POSModule/*: public InventoryManagementModule*/ {
    Manager* i;
    Cart* c;
    bool isCartEmpty = true;

public:

    POSModule(Manager* i, Cart* c) {
        this->i = i;
        this->c = c;
    }

	void addToCart() {
		cout << endl << "*******************Adding to Cart Utility*******************";
        string name;
        int quantity;
        int choice;
        cout << "\nEnter the name of the Product you want to add to cart: ";
        cin >> name;
        cout << "\nEnter quantity: ";
        cin >> quantity;
        cout << endl << "\nNumber of products: " << i->getNumberOfProducts();
        for (int i = 0; i < this->i->getNumberOfProducts(); i++) {
            if (name == this->i->getProducts()[i].getName()) {
                while (this->i->getProducts()[i].getQuantity() < quantity){
                    cout << "ERROR! Entered quantity is greater than availble. Do you want to\n1-Order more\n2-Re-Enter quantity\n3-Back\nSelect option: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        this->i->productOrdering();
                        break;
                    
                    case 2:
                        cout << "\nEnter Quantity: ";
                        cin >> quantity;
                        break;

                    case 3:
                        break;

                    default:
                        cout << "\nInvalid input";
                        break;
                    }

                    if (choice == 3) 
                        break;
                }
                
                if (this->i->getProducts()[i].getQuantity() >= quantity) {
                    this->i->getProducts()[i].setQuantity(this->i->getProducts()[i].getQuantity() - quantity);
                    c->addProduct(name, quantity, this->i->getProducts()[i].getPrice());
                    isCartEmpty = false;
                }

                break;
            }

            if (i == this->i->getNumberOfProducts() - 1) {
                cout << endl << "Product not found";
            }
        }

	}

	void applyDiscount() {
        string name;
        float discountRate;
		cout << "***************Apply Discount***************";
        cout << endl << "Enter the name of Product: ";
        cin >> name;
        for (int i = 0; i < this->i->getNumberOfProducts(); i++) {
            if (this->i->getProducts()[i].getName() == name) {
                cout << "Enter discount rate: ";
                cin >> discountRate;
                if (discountRate > 0)
                    this->i->getProducts()[i].setDiscount(discountRate);
                else 
                    cout << "ERROR: Discount rate cannot be negative";
            }
        }
	}

	void issueRefunds() {
        cout << "***************Issue Refunds***************";
        string name;
        int quantity;
        cout << endl << "Enter the name of Product: ";
        cin >> name;
        cout << endl << "Enter quantity: ";
        cin >> quantity;
        for (int i = 0; i < this->i->getNumberOfProducts(); i++) {
            if (this->i->getProducts()[i].getName() == name) {
                this->i->getProducts()[i].setQuantity(this->i->getProducts()[i].getQuantity() + quantity);
            }
        }
	}

};

class Salesman: public POSModule, public ReportingModule {
    private:


    public:
        Salesman(Manager* m, Cart* c): POSModule(m, c) {}
};

int main() {

    int choice;
    Manager* m = new Manager();
    Cart* c = new Cart();
    Salesman* s;
    while(choice != 3) {
        cout << "Enter choice (1-Manager, 2-Salesman, 3-Exit): ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                int choice = 0;
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
            {
                s = new Salesman(m, c);
                while(choice != 3) {
                    cout << "*********SALESMAN DASHBOARD**********";
                    cout << "\n1-POS Module\n2-Report Module\n3-Back\nSelect option: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        while (choice != 4) {
                            cout << endl << "**************POS MODULE*****************";
                            cout << endl << "1-Add to Cart\n2-Apply Discount\n3-Issue Refund\n4-Back\nSelect option: ";
                            cin >> choice;
                            switch (choice)
                            {
                            case 1:
                                s->addToCart();
                                break;

                            case 2:
                                s->applyDiscount();
                                break;

                            case 3:
                                s->issueRefunds();
                                break;

                            case 4:
                                break;
                            
                            default:
                                cout << "Invalid Input";
                                break;
                            }
                        }
                        break;

                    case 2:
                        cout << "****************Report Module****************";

                    case 3: 
                        break;
                    
                    default:
                        break;
                    }
                }
                break;
            }

            case 3:
            {
                cout << "********You terminated**********";
                break;
            }

            default:
            {
                cout << "Invalid input!";
                break;
            }
        }
    }

    return 0;
}
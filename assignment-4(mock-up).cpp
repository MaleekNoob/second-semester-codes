/*
*Name: Maleek Hussain Ali
*Roll Number: 22i-1526
*Section: B
*/

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

class Person {
    protected:
    string name, address, cnic;
    int age;

    public:
    Person(string n = "", string a="", string c="", int aa = 0) {
        name = n;
        address = a;
        cnic = c;
        age = aa;
    }

    virtual void print() = 0;

    virtual void display() {
        cout << endl << "Name: " << name;
        cout << endl << "Address: " << address;
        cout << endl << "CNIC: " << cnic;
        cout << endl << "Age: " << age;
    }
};

class Customer: public Person {
    Cart* c;
    double balance;

    public:
    Customer(Cart* c = nullptr, double b = 0) {
        this->c = c;
        balance = b;
    }

    void addToCart(Product p, int quantity) {
        c->addProduct(p.getName(), quantity, p.getPrice());
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

    void print() {
        Person::display();
        cout << endl << "Balance: " << balance;
        cout << endl << "Cart: ";
        c->display();
    }
};

/*Class of supplier*/
class Supplier: public Person {
    Product* p;
    int numberOfProducts;

    public:
    Supplier(Product* p = nullptr, int n = 0) {
        this->p = p;
        numberOfProducts = n;
    }

    void setProduct(Product* p) {
        this->p = p;
    }

    void setNumberOfProducts(int n) {
        this->numberOfProducts = n;
    }

    Product* getProduct() {
        return p;
    }

    int getNumberOfProducts() {
        return numberOfProducts;
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

    void print() {
        Person::display();
        cout << endl << "Products: ";
        for (int i = 0; i < numberOfProducts; i++) {
            cout << endl << "Product " << i + 1 << ": ";
            cout << p[i];
        }
    }
};

class InventoryManagementModule {
    protected:
    Product* p;
    Supplier* supplier;
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
                cout << endl << "******************Modifying exsisting Product******************";
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
        cout << endl << "**********************Product Taking Utility**********************";
        string name;
        int choice = 0;
        int quantity;
        cout << "\nEnter the name of the Product you want to take : ";
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

class Manager: public InventoryManagementModule {
    private:


    public:
        Manager() {}

};

class POSModule {
    Manager* i;
    Customer* c;

    protected:
    Product* items_Sold;
    int numberOfItemSold;

    void itemSold(Product p, int q) {
        int size = numberOfItemSold + 1;
        Product* temp = new Product[size];
        for (int i = 0; i < numberOfItemSold; i++) {
            temp[i] = items_Sold[i];
        }
        delete[] items_Sold;
        items_Sold = temp;
        numberOfItemSold = size;
        items_Sold[numberOfItemSold - 1] = p;
        items_Sold[numberOfItemSold - 1].setPrice(q * p.getPrice());
    }

public:

    int getNumberOfItemSold() {
        return numberOfItemSold;
    }

    POSModule(Manager* i, Customer* c) {
        this->i = i;
        this->c = c;
        numberOfItemSold = 0;
        items_Sold = nullptr;
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
                    itemSold(this->i->getProducts()[i], quantity);
                    c->addToCart(this->i->getProducts()[i], quantity);
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
        int choice = 0;
        float discountRate;
		cout << "***************Apply Discount***************";
        while (choice != 4) {
            cout << endl << "1-Set Discount\n2-Set Promotion\n3-Set Tax\n4-Back\nSelect option: ";
            cin >> choice;
            switch (choice)
            {
                case 1:
                    // apply discount
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
                break;

                case 2:
                    // apply promotion
                    cout << endl << "Enter the name of Product: ";
                    cin >> name;
                    for (int i = 0; i < this->i->getNumberOfProducts(); i++) {
                        if (this->i->getProducts()[i].getName() == name) {
                            cout << "Enter promotion rate: ";
                            cin >> discountRate;
                            if (discountRate > 0)
                                this->i->getProducts()[i].setPromotion(discountRate);
                            else 
                                cout << "ERROR: Promotion rate cannot be negative";
                        }
                    }
                break;

                case 3:
                    //apply Tax
                    cout << endl << "Enter the name of Product: ";
                    cin >> name;
                    for (int i = 0; i < this->i->getNumberOfProducts(); i++) {
                        if (this->i->getProducts()[i].getName() == name) {
                            cout << "Enter tax rate: ";
                            cin >> discountRate;
                            if (discountRate > 0)
                                this->i->getProducts()[i].setTax(discountRate);
                            else 
                                cout << "ERROR: Tax rate cannot be negative";
                        }
                    }
                break;

                case 4:
                    break;
                
                default:
                    cout << "Invalid input";
                    break;
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
                c->setBalance(c->getBalance() + (this->i->getProducts()[i].getPrice() * quantity));
            }
        }
	}

};

class ReportingModule: public POSModule {
    Manager* m;

public:
    ReportingModule(Manager* m, Customer* c): POSModule(m, c) {
        this->m = m;
    }

	void salesReport() {
        cout << endl << "*******************Sales Report Utility*******************";
		for (int i = 0; i < numberOfItemSold; i++) {
            cout << items_Sold[i];
            cout << endl << endl;
        }
	}

	void inventoryReport() {
		cout << endl << "*******************Inventory Report Utility*******************";
        for (int i = 0; i < m->getNumberOfProducts(); i++) {
            cout << m->getProducts()[i];
            cout << endl << endl;
        }
	}

	void profitReports() {
        cout << endl << "*******************Profit Report Utility*******************";
        float profit = 0;
        for (int i = 0; i < numberOfItemSold; i++) {
            profit += items_Sold[i].getPrice();
        }
        cout << endl << "Total Profit: " << profit;
	}

};

class Salesman: public ReportingModule {
    private:


    public:
        Salesman(Manager* m, Customer* c): ReportingModule(m, c) {}
};

int main() {

    int choice;
    Manager* m = new Manager();
    Cart* c = new Cart();
    Customer* customer = new Customer(c);
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

                    case 2:
                        while(choice != 4) {
                            cout << endl << "**************REPORT MODULE*****************";
                            cout << endl << "1-Sales Report\n2-Inventory Report\n3-Profit Report\n4-Back\nSelect option: ";
                            cin >> choice;
                            switch (choice)
                            {
                            case 1:
                                s->salesReport();
                                break;

                            case 2:
                                s->inventoryReport();
                                break;

                            case 3:
                                s->profitReports();
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
                s = new Salesman(m, customer);
                while(choice != 5) {
                    cout << "*********SALESMAN DASHBOARD**********";
                    cout << "\n1-POS Module\n2-Report Module\n5-Back\nSelect option: ";
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
                        while(choice != 4) {
                            cout << "\n1-Sales Report\n2-Inventory Report\n3-Profit Report\n4-Back\nSelect option:";
                            cin >> choice;
                            switch (choice)
                            {
                            case 1:
                                s->salesReport();
                                break;

                            case 2:
                                s->inventoryReport();
                                break;

                            case 3:
                                s->profitReports();
                                break;

                            case 4:
                                break;

                            default:
                                cout << "Invalid Input";
                                break;
                            }
                        }
                    
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
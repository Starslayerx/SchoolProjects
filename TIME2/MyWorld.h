#ifndef MyWORLD_H
#define MyWORLD_H

class MyWorld
{
    private:
        char * pdata;
        int length;
        const int cnumber;
    public:
        static int global;
        MyWorld();
        MyWorld(char *, int);
        //MyWorld(const MyWorld&);
        ~MyWorld();
        
        void single();
        void show() const;
        char* data() const { return pdata;}
        int len() const {return length;}

        MyWorld operator=(const MyWorld &b)
        {
            this->length = b.len();
            this->pdata = new char [this->length];
            memcpy(pdata, b.data(), this->length * sizeof(char));
            return b;
        }
        
        static void stest()
        {
            cout << "Static number: " << global << endl;
            ++global;
        }
};
int MyWorld::global(0);

// default copy constructor
MyWorld::MyWorld() : cnumber(6) { };

// swallow copy constructor
MyWorld::MyWorld(char * c, int n) : cnumber(6)
{
    length = n;
    pdata = c;
    for (int i = 0; i < length; ++i)
        pdata[i] = c[i];
}

/*
// deep copy constructor
MyWorld::MyWorld(const MyWorld &world)
{
    length = world.length;
    pdata = new char [length];
    memcpy(pdata, world.data(), length * sizeof(char));
}

// deep destructor
MyWorld::~MyWorld()
{
    delete[] pdata;
}
*/
MyWorld::~MyWorld() { }

/* 
 * This function can't change any number variables in object
   and also can only call const number variables 
   none const functoin can't call const number variables
 * Const object can only call const function
 */
void MyWorld::show() const
{
    cout << "Object text: ";
    for (int i = 0; i < length; ++i)
        cout << pdata[i];
    cout << endl;
    cout << "Const number: " << cnumber << endl;
}

void MyWorld::single()
{
    for (int i = 0; i < length; ++i)
    {
        cout << pdata[i];
    }
}
#endif

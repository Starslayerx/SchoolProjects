#ifndef MyWORLD_H
#define MyWORLD_H

class MyWorld
{
    private:
        char * pdata;
        int length;
    public:
        static int global;
        MyWorld();
        MyWorld(char *, int);
        //MyWorld(const MyWorld&);
        ~MyWorld();
        
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
};

// default copy constructor
MyWorld::MyWorld() { };

// swallow copy constructor
MyWorld::MyWorld(char * c, int n)
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

// only for deep constructor
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
    //cout << "static number: " << global << endl;
}

#endif

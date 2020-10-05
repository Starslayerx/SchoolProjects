#ifndef SLOUTION_H
#define SLOUTION_H

class Sloution
{
    public:
    	string sloution(int a, int b)
        {
            // if a is 0, result is 0
            if (a == 0)
                return "Not a circulation. Result is 0";
            
            vector <char> c;

            // if a or b < 0, add '-'
            if (a*b < 0)
            {
                c.push_back('-');
                a = labs(a);
                b = labs(b);
            }

            int remainder;
            string consult;
            //if a >= b, make a < b
            if (a >= b)
            {
                consult = to_string(a / b);
                for (int i = 0; i < consult.size(); ++i)
                    c.push_back(consult[i]);
                a %= b;
                remainder = a;
            }
            else
            {
                c.push_back('0');
                remainder = a % b;
            }

            c.push_back('.');
            map <int, int> m;
            unsigned int length{0};
            // fraction part
            while (remainder != 0)
            {
                // didn't find same remainder
                if (m.find(remainder) == m.end()) 
                {
                    ++length;
                    m[remainder] = c.size();
                    remainder *= 10;
                    c.push_back((remainder / b) + '0');
                    remainder %= b;
                }
                else
                {
                    c.insert(c.begin() + m[remainder], '(');
                    c.push_back(')');
                    break;
                }
            }
            // not a circulation aprt
            if (remainder == 0)
            {
                return "Not a circulation, and the number is:" + string(c.begin(), c.end());
            }

            return  "Is a cirfculation, and the number is:" + string(c.begin(), c.end()) + "\nThe length of circulation is:" + to_string(length) ;
        }
};

#endif

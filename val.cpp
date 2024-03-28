#include "val.h"
#include <string>
#include <cmath>

Value Value::operator*(const Value &op) const
{
    // convert 2nd to real
    double oper;
    double num1;
    if (IsReal() && op.IsString())
    {
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(GetReal() * oper);
    }
    // Convert both to reals
    else if (IsString() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(num1 * oper);
    }
    // convert first one
    else if (IsString() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

        return Value(num1 * op.GetReal());
    }

    else if (IsReal() && op.IsReal())
    {
        return Value(GetReal() * op.GetReal());
    }
    else
        return Value();
}

Value Value::SLthan(const Value &op) const
{
    string oper;
    string str1;

    // convert first one
    if (IsReal() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetReal();
            str1 = outStr1.str();
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        return Value(str1 < op.GetString());
    }
    // Convert both to strings
    else if (IsReal() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetReal();
            str1 = outStr1.str();
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }

        try
        {
            oper = to_string(op.GetReal());
            oper.erase(oper.find_last_not_of('0') + 1, string::npos);
            oper.erase(oper.find_last_not_of('.') + 1, string::npos);
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        return Value(str1 < oper);
    }
    // convert second one
    else if (IsString() && op.IsReal())
    {
        try
        {
            oper = to_string(op.GetReal());
            oper.erase(oper.find_last_not_of('0') + 1, string::npos);
            oper.erase(oper.find_last_not_of('.') + 1, string::npos);
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }

        return Value(GetString() < oper);
    }

    else if (IsString() && op.IsString())
    {
        return Value(GetString() < op.GetString());
    }
    else
        return Value();
}
Value Value::SGthan(const Value &op) const
{
    string oper;
    string str1;

    // convert first one
    if (IsReal() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetReal();
            str1 = outStr1.str();
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        return Value(str1 > op.GetString());
    }
    // Convert both to strings
    else if (IsReal() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetReal();
            str1 = outStr1.str();
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }

        try
        {
            oper = to_string(op.GetReal());
            oper.erase(oper.find_last_not_of('0') + 1, string::npos);
            oper.erase(oper.find_last_not_of('.') + 1, string::npos);
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        return Value(str1 > oper);
    }
    // convert second one
    else if (IsString() && op.IsReal())
    {
        try
        {
            oper = to_string(op.GetReal());
            oper.erase(oper.find_last_not_of('0') + 1, string::npos);
            oper.erase(oper.find_last_not_of('.') + 1, string::npos);
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }

        return Value(GetString() > oper);
    }

    else if (IsString() && op.IsString())
    {
        return Value(GetString() > op.GetString());
    }
    else
        return Value();
}

Value Value::SEqual(const Value &op) const
{
    string oper;
    string str1;

    // convert first one
    if (IsReal() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetReal();
            str1 = outStr1.str();
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        return Value(str1 == op.GetString());
    }
    // Convert both to strings
    else if (IsReal() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetReal();
            str1 = outStr1.str();
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        try
        {
            oper = to_string(op.GetReal());
            oper.erase(oper.find_last_not_of('0') + 1, string::npos);
            oper.erase(oper.find_last_not_of('.') + 1, string::npos);
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        return Value(str1 == oper);
    }
    // convert second one
    else if (IsString() && op.IsReal())
    {
        try
        {
            oper = to_string(op.GetReal());
            oper.erase(oper.find_last_not_of('0') + 1, string::npos);
            oper.erase(oper.find_last_not_of('.') + 1, string::npos);
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }

        return Value(GetString() < oper);
    }

    else if (IsString() && op.IsString())
    {
        //cout<<GetString()<<endl;
        //cout<<op.GetString()<<endl;
        return Value(GetString() == op.GetString());
    }
    else
        return Value();
}

Value Value::operator==(const Value &op) const
{
    double oper;
    double num1;

    if (IsReal() && op.IsString())
    {
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(GetReal() == oper);
    }
    // Convert both to reals
    else if (IsString() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(num1 == oper);
    }
    // convert first one
    else if (IsString() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

        return Value(num1 == op.GetReal());
    }

    else if (IsReal() && op.IsReal())
    {
        return Value(GetReal() == op.GetReal());
    }
    else
        return Value();
}

Value Value::operator^(const Value &op) const
{

    if ((IsReal() || IsInt()) && (op.IsReal() || op.IsInt()))
        if (IsReal() && op.IsReal())
            return Value(pow(GetReal(), op.GetReal()));
        else if (IsReal() && op.IsInt())
            return Value(pow(GetReal(), op.GetInt()));
        else if (IsInt() && op.IsInt())
            return Value(pow(GetInt(), op.GetInt()));
        else
            return Value(pow(GetInt(), op.GetReal()));

    else
        return Value();
}

Value Value::Catenate(const Value &op) const
{
    string oper;
    string str1;
    // convert first one
    if (IsReal() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetReal();
            str1 = outStr1.str();
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        // cout<<"String conversion"<<str1<<endl;
        return Value(str1 + op.GetString());
    }
    // Convert both to reals
    else if (IsReal() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetReal();
            str1 = outStr1.str();
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        try
        {
            oper = to_string(op.GetReal());
            oper.erase(oper.find_last_not_of('0') + 1, string::npos);
            oper.erase(oper.find_last_not_of('.') + 1, string::npos);
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }
        return Value(str1 + oper);
    }
    // convert second one
    else if (IsString() && op.IsReal())
    {
        try
        {
            oper = to_string(op.GetReal());
            oper.erase(oper.find_last_not_of('0') + 1, string::npos);
            oper.erase(oper.find_last_not_of('.') + 1, string::npos);
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from double to string." << endl;
            return Value();
        }

        return Value(GetString() + oper);
    }

    else if (IsString() && op.IsString())
    {
        return Value(GetString() + op.GetString());
    }
    else
        return Value();
}

Value Value::operator+(const Value &op) const
{
    double oper;
    double num1;

    if (IsReal() && op.IsString())
    {
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(GetReal() + oper);
    }
    // Convert both to reals
    else if (IsString() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(num1 + oper);
    }
    // convert first one
    else if (IsString() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

        return Value(num1 + op.GetReal());
    }

    else if (IsReal() && op.IsReal())
    {
        return Value(GetReal() + op.GetReal());
    }
    else
        return Value();
}
Value Value::operator>(const Value &op) const
{
    double oper;
    double num1;

    if (IsReal() && op.IsString())
    {
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(GetReal() > oper);
    }
    // Convert both to reals
    else if (IsString() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(num1 > oper);
    }
    // convert first one
    else if (IsString() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

        return Value(num1 > op.GetReal());
    }

    else if (IsReal() && op.IsReal())
    {
        return Value(GetReal() > op.GetReal());
    }
    else
        return Value();
}

Value Value::operator<(const Value &op) const
{
    double oper;
    double num1;
    if (IsReal() && op.IsString())
    {
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(GetReal() < oper);
    }
    // Convert both to reals
    else if (IsString() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(num1 < oper);
    }
    // convert first one
    else if (IsString() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

        return Value(num1 < op.GetReal());
    }

    else if (IsReal() && op.IsReal())
    {
        return Value(GetReal() < op.GetReal());
    }
    else
        return Value();
}

Value Value::operator-(const Value &op) const
{
    double oper;
    double num1;

    if (IsReal() && op.IsString())
    {
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(GetReal() - oper);
    }
    // Convert both to reals
    else if (IsString() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(num1 - oper);
    }
    // convert first one
    else if (IsString() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }

        return Value(num1 - op.GetReal());
    }

    else if (IsReal() && op.IsReal())
    {
        return Value(GetReal() - op.GetReal());
    }
    else
        return Value();
}

Value Value::operator/(const Value &op) const
{
    double oper;
    double num1;

    if (IsReal() && op.IsString())
    {
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        if (oper == 0)
        {
            cout << "Invalid division by 0." << endl;
            return Value();
        }
        return Value(GetReal() / oper);
    }
    // Convert both to reals
    else if (IsString() && op.IsString())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        if (oper == 0)
        {
            cout << "Invalid division by 0." << endl;
            return Value();
        }
        return Value(num1 / oper);
    }
    // convert first one
    else if (IsString() && op.IsReal())
    {
        try
        {
            ostringstream outStr1;
            outStr1 << GetString();
            num1 = std::stod(outStr1.str());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        if (op.GetReal() == 0)
        {
            cout << "Invalid division by 0." << endl;
            return Value();
        }

        return Value(num1 / op.GetReal());
    }

    else if (IsReal() && op.IsReal())
    {
        if(op.GetReal() == 0){
            cout << "Invalid division by 0." << endl;
            return Value();
        }
        return Value(GetReal() / op.GetReal());
    }
    else
        return Value();
}

// String ** Numeric
Value Value::Repeat(const Value &op) const
{
    // First operands is a string and the second operand is an integer
    double oper;
    if (IsString() && op.IsString())
    {
        // cout<<GetString() + " " + op.GetString()<<endl;
        // second operand must be converted to a numeric
        try
        {
            oper = stod(op.GetString());
            // cout<<"invalid arg"<<endl;//may throw invalid_argument()
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        int times = oper;
        string str = GetString(), newstr = "";
        for (int i = 1; i <= times; i++)
        {
            newstr += str;
        }
        // cout<<newstr<<endl;
        return Value(newstr);
    }

    else if ((IsReal() || IsInt()) && op.IsString())
    {
        // Both operands to be converted
        // first operand must be converted to a string
        ostringstream outStr1;
        if (IsReal())
            outStr1 << GetReal();
        else
            outStr1 << GetInt();
        string stroper1 = outStr1.str(), newstr = "";
        // second operand must be converted to a numeric
        try
        {
            oper = stod(op.GetString());
        }
        catch (invalid_argument &arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        int times = oper;
        for (int i = 1; i <= times; i++)
        {
            newstr += stroper1;
        }
        return Value(newstr);
    }
    else if (IsString() && (op.IsReal() || op.IsInt()))
    {
        int times;
        if (op.IsInt())
            times = op.GetInt();
        else
            times = op.GetReal();
        string newstr;
        for (int i = 1; i <= times; i++)
        {
            newstr += GetString();
        }
        return Value(newstr);
    }
    // Convert First one only
    else if (IsReal() && op.IsReal())
    {
        ostringstream outStr1;
        outStr1 << GetReal();
        string stroper1 = outStr1.str(), newstr = "";
        int times = op.GetReal();
        for (int i = 1; i <= times; i++)
        {
            newstr += stroper1;
        }
        return Value(newstr);
    }
    else
        return Value();
}

/*// numeric overloaded add op to this
    Value operator+(const Value& op) const; -

    // numeric overloaded subtract op from this
    Value operator-(const Value& op) const; -

    // numeric overloaded multiply this by op
    Value operator*(const Value& op) const; -

    // numeric overloaded divide this by op
    Value operator/(const Value& op) const; -
    //numeric overloaded equality operator of this with op
    Value operator==(const Value& op) const; !
    //numeric overloaded greater than operator of this with op
    Value operator>(const Value& op) const; !
    //numeric overloaded less than operator of this with op
    Value operator<(const Value& op) const; !

    //Numeric exponentiation operation this raised to the power of op
    Value operator^(const Value& oper) const; -

    //string concatenation operation of this with op
    Value Catenate(const Value& oper) const; -
    //string repetition operation of this with op
    Value Repeat(const Value& oper) const; -
    //string equality (-eq) operator of this with op
    Value SEqual(const Value& oper) const; -
    //string greater than (-gt) operator of this with op
    Value SGthan(const Value& oper) const; -
    //string less than operator of this with op
    Value SLthan(const Value& oper) const; -
*/
#include "BigInt.h"

BigInt::BigInt()
{
    numb_ = '0';
}

BigInt::BigInt(std::string s)
{
    numb_ = s;
}

BigInt::BigInt(unsigned long long n)
{
    do {
        numb_.push_back(n % 10);
        n /= 10;
    } while (n);
}

BigInt::BigInt(const BigInt& other)
{
    numb_ = other.numb_;
}

BigInt::BigInt(BigInt&& other) noexcept
{
    numb_ = other.numb_;
}

std::string BigInt::get_num()
{
    return numb_;
}

std::string BigInt::trim(std::string s) 
{                       
    if (s == "0")
        return s;
    if (s[0] == '-') 
    {
        int i = 1;
        while (s[i] == '0')
        {
            s.erase(i, 1);
        }
        return s;
    }
    else if (s[0] == '0') 
    {
        int i = 0;
        while (s[i] == '0')
        {
            s.erase(i, 1);
        }
        return s;
    }
    return s;
}

std::string BigInt::maximum(std::string str1, std::string str2) 
{             
    std::string max = "";
    bool bothNeg = false;
    bool isMax1 = false;
    bool isMax2 = false;
    if (str1[0] == '-' && str2[0] == '-') 
    {
        bothNeg = true;
        str1.erase(0, 1);
        str2.erase(0, 1);
    }
    else if (str1[0] == '-') 
    {
        return trim(str2);
    }
    else if (str2[0] == '-') 
    {
        return trim(str1);
    }
    int str1_len = str1.length(), str2_len = str2.length();
    if (str1_len == str2_len) 
    {
        for (int i = 0; i < str1_len; ++i) 
        {
            if (str1[i] != str2[i])
            {
                if (str1[i] > str2[i])
                {
                    isMax1 = true;
                }
                else 
                {
                    isMax2 = true;
                }
                break;
            }
        }
        if (!(isMax2 ^ isMax1)) 
        {
            isMax1 = true;
        }
    }
    else if (str1_len > str2_len) 
    {
        isMax1 = true;
    }
    else 
    {
        isMax2 = true;
    }
    if (bothNeg) 
    {
        if (isMax1)
            return ("-" + trim(str2));
        else
            return ("-" + trim(str1));
    }
    else 
    {
        if (isMax1)
            return trim(str1);
        else
            return trim(str2);
    }
}

std::string BigInt::subtract(std::string str1, std::string str2) 
{       
    int str1_len = str1.length();
    int str2_len = str2.length();
    std::string sum = "";
    if (str1 == str2) 
    {
        return "0";
    }
    else if (str1[0] == '-' && str2[0] == '-') 
    {
        if (str2_len == 1 && str1_len == 1) 
        {
            sum = "0";
        }
        else 
        {
            BigInt t1(str1.erase(0, 1));
            BigInt t2(str2.erase(0, 1));
            std::string temp = subtract(t2.numb_, t1.numb_);
            BigInt mx = maximum(t2.numb_, t1.numb_);
            if (temp[0] != '-' && mx.numb_ == t1.numb_)
                sum = "-" + temp;
            else
                sum = temp;
        }
    }
    else if (str1[0] == '-') 
    {
        sum = "-" + add(str1.erase(0, 1), str2);
    }
    else if (str2[0] == '-') 
    {
        sum = add(str1, str2.erase(0, 1));
    }
    else
    {
        int i, j, track_sum, carry = 0;
        if (str1_len < str2_len) {
            std::string tp = str1;
            str1 = str2;
            str2 = tp;
            sum = "-" + subtract(str1, str2);
            return trim(sum);
        }
        else if (str1_len == str2_len) {
            BigInt a(str1);
            BigInt b(str2);
            BigInt mx = maximum(a.numb_, b.numb_);
            if (mx.numb_ == str2) {
                std::string tp = str1;
                str1 = str2;
                str2 = tp;
                BigInt t1(str1);
                BigInt t2(str2);
                BigInt temp = subtract(str1, str2);
                sum = "-" + subtract(str1, str2);
                return trim(sum);
            }
        }
        int val1, val2;
        for (i = str1_len - 1, j = str2_len - 1; i >= 0 || j >= 0; --i, --j) {
            if (i >= 0) {
                val1 = (int)str1[i] - 48;
            }
            else {
                val1 = 0;
            }
            if (j >= 0) {
                val2 = (int)str2[j] - 48;
            }
            else {
                val2 = 0;
            }
            track_sum = val1 - val2 - carry;
            if (track_sum < 0) {
                track_sum += 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            sum = std::to_string(track_sum) + sum;
        }
    }
    return trim(sum);
}

std::string BigInt::add(std::string s1, std::string s2)
{
    int s1_len = s1.length();
    int s2_len = s2.length();
    std::string sum = "";

    if (s1_len == 0 && s2_len == 0) 
    {
        sum = "0";
    }
    else if (s1[0] == '-' && s2[0] == '-') 
    {
        if (s1_len == 1 && s2_len == 1) 
        {
            sum = "0";
        }
        else 
        {
            sum = "-" + add(s1.erase(0, 1), s2.erase(0, 1));
        }
    }
    else if (s1[0] == '-') 
    {
        sum = subtract(s2, s1.erase(0, 1));
    }
    else if (s2[0] == '-') 
    {
        sum = subtract(s1, s2.erase(0, 1));
    }
    else 
    {
        int i, j, track_sum, carry = 0;
        for (i = s1_len - 1, j = s2_len - 1; i >= 0 && j >= 0; --i, --j) 
        {
            track_sum = (static_cast<int>(s1[i])) - 48 + (static_cast<int>(s2[j])) - 48 + carry;
            carry = track_sum / 10;
            sum = std::to_string(track_sum % 10) + sum;
        }
        if (i >= 0 && j < 0) 
        {
            for (; i >= 0; --i) 
            {
                track_sum = (static_cast<int>(s1[i])) - 48 + carry;
                carry = track_sum / 10;
                sum = std::to_string(track_sum % 10) + sum;
            }
        }
        else if (j >= 0 && i < 0)
        {
            for (; j >= 0; --j) 
            {
                track_sum = (static_cast<int>(s2[j])) - 48 + carry;
                carry = track_sum / 10;
                sum = std::to_string(track_sum % 10) + sum;
            }
        }
        if (carry) 
        {
            sum = std::to_string(carry) + sum;
        }
    }
    return trim(sum);
}

std::string BigInt::multiply(std::string str1, std::string str2)
{          
    bool toAddNeg = false;
    int str1_len = str1.length();
    int str2_len = str2.length();
    std::string ans = "";
    if (str1[0] == '-' && str2[0] == '-') 
    {
        ans = multiply(str1.erase(0, 1), str2.erase(0, 1));
    }
    else if (str1[0] == '-') 
    {
        toAddNeg = true;
        ans = multiply(str1.erase(0, 1), str2);
    }
    else if (str2[0] == '-') 
    {
        toAddNeg = true;
        ans = multiply(str1, str2.erase(0, 1));
    }
    else 
    {
        if (str1_len == 0 || str2_len == 0)
            return "0";
        std::vector<int> result(str1_len + str2_len, 0);
        int i_n1 = 0;
        int i_n2 = 0;
        for (int i = str1_len - 1; i >= 0; i--) 
        {
            int carry = 0;
            int n1 = str1[i] - '0';
            i_n2 = 0;
            for (int j = str2_len - 1; j >= 0; j--) 
            {
                int n2 = str2[j] - '0';
                int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }
            if (carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }
        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0)
            i--;
        if (i == -1)
            return "0";
        while (i >= 0)
            ans += std::to_string(result[i--]);
    }
    if (toAddNeg && ans[0] != '0') 
    {
        ans = '-' + ans;
    }
    return ans;
}

BigInt& BigInt::operator=(const BigInt& other)
{
    if (&other != this)
    {
        numb_ = other.numb_;
    }
    return *this;
}

BigInt& BigInt::operator=(BigInt&& other) noexcept
{
    if (&other != this)
    {
        numb_ = other.numb_;
    }
    return *this;
}

BigInt BigInt::operator+(const BigInt& other)
{
    BigInt ans;
    ans.numb_ = add(numb_, other.numb_);
    return ans;
}

BigInt BigInt::operator*(const int numb)
{
    BigInt ans;
    ans.numb_ = multiply(numb_, std::to_string(numb));
    return ans;
}

BigInt BigInt::operator * (BigInt const& other) 
{
    BigInt ans;
    ans.numb_ = multiply(numb_, other.numb_);
    return ans;
}
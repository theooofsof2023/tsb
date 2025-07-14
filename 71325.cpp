#include <bits/stdc++.h>
using namespace std;

int g = 3;
int y = 1;
int r = 0;
int b = 8;
int e = 1;
int t = g + y + r + b + e;

pair<int, int> iv(int n, int h, bool is_event) {
    if (is_event) {
        return {1, 1}; 
    }
    int s = (h * (h + 1)) / 2;
    int numerator = h - n + 1;
    return {numerator, s};
}

pair<int, int> tv(int count, int t, bool is_event) {
    int e = 1; 
    int numerator = is_event ? (t - 1) : (t - count);
    int denominator = t * (3 + e);
    return {numerator, denominator};
}

pair<int, int> cv(pair<int,int> tv_frac, pair<int,int> iv_frac) {
    int numerator = tv_frac.first * iv_frac.first;
    int denominator = tv_frac.second * iv_frac.second;
    return {numerator, denominator};
}

int main() {
    int n, h;
    string type;

    cout << "Type the number of your card: ";
    cin >> n;

    cout << "Type the color of your card, type 'event' if it is a special card: ";
    cin >> type;

    if (type == "red") {
        h = r;
    }
    else if (type == "blue") {
        h = b;
    }
    else if (type == "yellow") {
        h = y;
    }
    else if (type == "green") {
        h = g;
    }
    else if (type == "event") {
        h = e;
    } else {
        cout << "Unknown card color." << endl;
        return 1;
    }

    if (n < 1 || n > h) {
        cout << "Invalid card number for this color." << endl;
        return 1;
    }

    bool is_event = (type == "event");
    pair<int, int> individualValue = iv(n, h, is_event);
    pair<int, int> typeValue = tv(h, t, is_event);
    pair<int, int> combinedValue = cv(typeValue, individualValue);

    cout << "IV: " << individualValue.first << "/" << individualValue.second << endl;
    cout << "TV: " << typeValue.first << "/" << typeValue.second << endl;
    cout << "CV: " << combinedValue.first << "/" << combinedValue.second << endl;

    return 0;
}

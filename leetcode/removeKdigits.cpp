string removeKDigits(string num, int k) {
    if (k == num.size())
        return "0";

    if (k == 0)
        return num;

    stack<char> list;

    for (int i = 0; i < num.length(); i++) {
        while (!list.empty() && k > 0 && list.top() > num[i]) {
            list.pop();
            k--;
        }

        list.push(num[i]);
    }

    for (int i = 0; i < k; i++) {
        list.pop();
    }

    string res = "";
    while(!list.empty()) {
        res+=list.top();
        list.pop();
    }
    reverse(res.begin(),res.end());
    while(res[0] == '0')
        res.erase(0,1);
    return res;
}

int main() {
    cout << removeKDigits("112", 1);
    return 0;
}

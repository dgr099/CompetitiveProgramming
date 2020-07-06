#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        bool id = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                if ((i == j && x != 1) || (i != j && x != 0))
                    id = false;
            }

        cout << (id ? "SI" : "NO") << endl;
    }

    return 0;
}
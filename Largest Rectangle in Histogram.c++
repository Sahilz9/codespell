#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> left(vector<int>& heights) {
        int n = heights.size();
        vector<int> v;
        int pseudoCode = -1;
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            if (s.size() == 0) {
                v.push_back(pseudoCode);
            } else if (s.size() > 0 && s.top().first < heights[i]) {
                v.push_back(s.top().second);
            } else if (s.size() > 0 && s.top().first >= heights[i]) {
                while (s.size() > 0 && s.top().first >= heights[i]) {
                    s.pop();
                }
                if (s.size() == 0) {
                    v.push_back(pseudoCode);
                } else {
                    v.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }
        return v;
    }

    vector<int> right(vector<int>& heights) {
        int n = heights.size();
        vector<int> v;
        int pseudoCode = n;
        stack<pair<int, int>> s;
        for (int i = n - 1; i >= 0; --i) {
            if (s.size() == 0) {
                v.push_back(pseudoCode);
            } else if (s.size() > 0 && s.top().first < heights[i]) {
                v.push_back(s.top().second);
            } else if (s.size() > 0 && s.top().first >= heights[i]) {
                while (s.size() > 0 && s.top().first >= heights[i]) {
                    s.pop();
                }
                if (s.size() == 0) {
                    v.push_back(pseudoCode);
                } else {
                    v.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }

        reverse(v.begin(), v.end());
        return v;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> r = right(heights);
        vector<int> l = left(heights);

        vector<int> width(n);

        for (int i = 0; i < n; i++) {
            width[i] = r[i] - l[i] - 1;
        }

        vector<int> area(n);

        for (int i = 0; i < n; i++) {
            area[i] = heights[i] * width[i];
        }

        int max_area = *max_element(area.begin(), area.end());

        return max_area;
    }
};

int main() {
    int n;
    cout << "Enter the number of heights: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    Solution solution;
    int max_area = solution.largestRectangleArea(heights);

    cout << "Largest rectangle area: " << max_area << endl;

    return 0;
}

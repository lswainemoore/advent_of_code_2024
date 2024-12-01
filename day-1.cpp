#include <iostream>
#include <fstream>
#include <map>

std::ifstream infile("day-1-input.txt");


int main() {

    std::vector<int> left;
    std::vector<int> right;

    std::map<int,int> right_counter;

    int a, b;
    while (infile >> a >> b)
    {
        // process pair (a,b)
        left.push_back(a);
        right.push_back(b);

        right_counter[b]++;
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int running_sum = 0;
    int running_similarity_score = 0;
    for (int i = 0; i < left.size(); i++) {
        // part 1
        running_sum += std::abs(left[i] - right[i]);

        // part 2
        running_similarity_score += (left[i] * right_counter[left[i]]);
    }
    
    std::cout << running_sum << std::endl;
    std::cout << running_similarity_score << std::endl;
}
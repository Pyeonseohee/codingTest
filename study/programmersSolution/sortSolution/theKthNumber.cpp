// void printVector(vector<int> v)
// {
//     for(int i = 0; i < v.size(); i++)
//         cout << "v[" << i << "]: " << v[i] << endl;
// }

#include <string>
#include <vector>

using namespace std;

void quickSort(vector<int>& v, int start, int end)
{
    if(start >= end) return;
    int pivot = start;
    int i = start + 1; // high를 찾는 인덱스
    int j = end; // low를 찾는 인덱스

    while(i <= j){
        while(v[i] <= v[pivot] && i <= end) i++; //v[i]가 pivot의 값보다 high한 값을 찾을 때까지
        while(v[j] >= v[pivot] && j > start) j--;
        if(i > j){ // 엇갈리면
            swap(v[j], v[pivot]);
        }else{
            swap(v[j], v[i]);
        }
    }
    quickSort(v, start, j - 1);
    quickSort(v, j + 1, end);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++)
    {
        vector<int> tmp; // 0으로 자동초기화
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            tmp.push_back(array[j]);
        }
        quickSort(tmp, 0, tmp.size() - 1);
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    return answer;
}
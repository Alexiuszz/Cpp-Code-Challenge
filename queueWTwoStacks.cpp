#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Queue
{
  stack<long> stack1, stack2;

  bool empty()
  {
    return stack1.empty() && stack2.empty();
  }
  int size()
  {
    return stack1.size() + stack2.size();
  }

  void Enqueue(long newItem)
  {
    stack1.push(newItem);
  }

  void Dequeue()
  {
    if (stack2.empty())
      while (!stack1.empty())
      {
        stack2.push(stack1.top());
        stack1.pop();
      }
    return stack2.pop();
  }

  long PrintFront()
  {
    if (stack2.empty())
    {
      while (!stack1.empty())
      {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    return stack2.top();
  }
};

int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  Queue q;
  long input;
  int numQueries;
  long elementEnqueue;
  long printedOut;
  string outString;
  cin >> numQueries;
  vector<long> outputs;

  for (int i = 0; i < numQueries; i++)
  {

    cin >> input;

    if (input == 1)
    {
      cin >> elementEnqueue;
      q.Enqueue(elementEnqueue);
    }
    if (input == 2)
    {
      q.Dequeue();
    }
    if (input == 3)
    {
      printedOut = q.PrintFront();
      outputs.push_back(printedOut);
    }
  }

  for (int i = 0; i < outputs.size(); i++)
  {
    cout << outputs[i] << endl;
  }

  return 0;
}
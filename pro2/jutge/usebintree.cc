#include "BinTree.hh"

typedef BinTree<string> BT;

/*
int main()
{
  BT t1;              // t1 = () =
  BT t2("a", t1, t1); // t2 = a((),()) = a(,) = a
  BT t3("b", t2, t1); // t3 = b(a,)
  BT t4("c", t2, t3); // t4 = c(a,b(a,))
  BT t5("d", t4, t3); // t5 = d(c(a,b(a,)),b(a,))
  t5.setOutputFormat(BT::INLINEFORMAT);
  cout << t5 << endl;
  t5.setOutputFormat(BT::VISUALFORMAT);
  cout << t5 << endl;
  BT t6 = t5.left();
  t6.setOutputFormat(BT::VISUALFORMAT);
  cout << t6 << endl;
  BT t7 = t5.right();
  t7.setOutputFormat(BT::VISUALFORMAT);
  cout << t7 << endl;
  BT t8 = t5.left().right();
  t8.setOutputFormat(BT::VISUALFORMAT);
  cout << t8 << endl;
  cout << t5.value() << endl;
  cout << t5.empty() << endl;
  // Wrong:
  // t5.left() = BT("a");
  // Instead:
  t5 = BT(t5.value(), BT("a"), t5.right());
  t5.setOutputFormat(BT::VISUALFORMAT);
  cout << t5 << endl;
}
*/

/*
int main()
{
  BT t;
  t.setInputFormat(BT::INLINEFORMAT);
  t.setOutputFormat(BT::VISUALFORMAT);
  while (cin >> t)
    cout << t << endl;
}
*/

int main(int argc, char *argv[])
{
  if (argc != 2) {
    cout << "Error: parameter 'n' expected but not found" << endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  BT t;
  for (int i = 1; i <= n; i++)
    t = BT(to_string(i), t, t);
  //t.setOutputFormat(BT::VISUALFORMAT);
  //cout << t << endl;
}

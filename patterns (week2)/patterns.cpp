#include <iostream>
using namespace std;
int main() {
  // int n;
  // cin >> n;
  // Solid Half Diamond
  //  for (int row = 0; row < n; row++) {
  //    for (int col = 0; col < row + 1; col++) {
  //      cout << "*";
  //    }
  //    cout << endl;
  //  }
  //  for (int row = 0; row < n - 1; row++) {
  //    for (int col = 0; col < n - row - 1; col++) {
  //      cout << "*";
  //    }
  //    cout << endl;
  //  }

  // BUTTERFLY PATTERN
  //  int num;
  //  cin >> num;
  //  int n = num / 2;
  //  for (int row = 0; row < n; row++) {
  //    for (int col = 0; col < row + 1; col++) {
  //      cout << "*";
  //    }
  //    for (int col = 0; col < 2 * n - 2 * row - 2; col++) {
  //      cout << " ";
  //    }
  //    for (int col = 0; col < row + 1; col++) {
  //      cout << "*";
  //    }
  //    cout << endl;
  //  }
  //  for (int row = 0; row < n; row++) {
  //    for (int col = 0; col < n - row; col++) {
  //      cout << "*";
  //    }
  //    for (int col = 0; col < 2 * row; col++) {
  //      cout << " ";
  //    }
  //    for (int col = 0; col < n - row; col++) {
  //      cout << "*";
  //    }
  //    cout << endl;
  //  }

  // Numeric Hollow inverted half pyramid
  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < n - row; col++) {
  //     if (col == 0 || col == n - row - 1 || row == 0)
  //       cout << col + row + 1;
  //     else
  //       cout << " ";
  //   }
  //   cout << endl;
  // }
  // Numeric Hollow half pyramid
  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < row + 1; col++) {
  //     if (col == 0 || col == row || row == n - 1)
  //       cout << col + 1;
  //     else
  //       cout << " ";
  //   }
  //   cout << endl;
  // }

  // alphabet pattern
  //  for (int row = 0; row < n; row++) {
  //    char ch;
  //    for (int col = 0; col < row + 1; col++) {
  //      ch = col + 1 + 'A' - 1;
  //      cout << ch;
  //    }

  //   for (char alphabet = ch; alphabet > 'A';) {
  //     alphabet--;
  //     cout << alphabet;
  //   }
  //   cout<<endl;
  // }
  // hollow inverted star pattern
  // star +number pattern
  //  for (int row = 0; row < n; row++) {
  //    int totalcol = row + 1;
  //    for (int col = 0; col < totalcol; col++) {
  //      if (col == totalcol - 1) {
  //        cout << row + 1;
  //      } else {
  //        cout << row + 1 << "*";
  //      }
  //    }
  //    cout << endl;
  //  }

  // for (int row = 0; row < n; row++) {
  //   int totalcol = n - row - 1;
  //   for (int col = 0; col < n - row - 1; col++) {
  //     if (col == (n - row - 1) - 1) {
  //       cout << totalcol;
  //     } else {
  //       cout << totalcol << "*";
  //     }
  //   }

  //   cout << endl;
  // }

  // hollow inverted star pattern
  //  for (int row = 0; row < n; row++) {
  //    for (int col = 0; col < n - row; col++) {
  //      if (row == 0 || row == n - 1) {
  //        cout << "*";
  //      } else {
  //        if (col == 0 || col == n - row - 1) {
  //          cout << "*";
  //        } else
  //          cout << " ";
  //      }
  //    }
  //    cout << endl;
  //  }
  //  doubt
  //   for (int row = 0; row < n; row++) {
  //     int totalcol = row + 1;
  //     for (int col = 0; col < totalcol; col++) {
  //       if (col == totalcol - 1) {
  //         cout << row + 1;
  //       } else {
  //         cout << row + 1 << "*";
  //       }
  //     }
  //     cout << endl;
  //   }
  //   for (int row = 0; row < ; row++) {
  //     for (int col = 0; col < totalcol; col++) {
  //       }
  //     }
  //     cout << endl;
  //   }
  //   numbers + star pattern
  //    for (int row = 0; row < n; row++) {
  //      for (int col = 0; col < 2 * row + 1; col++) {
  //        if (col % 2 != 0) {
  //          cout << "*";
  //        } else
  //          cout << row + 1;
  //      }
  //      cout << endl;
  //    }

  int num;
  cin >> num;
  int n = num / 2;
  for (int row = 0; row < n; row++) {
    // inverted half pyramid 1
    for (int col = 0; col < n - row; col++) {
      cout << "*";
    }

    // full pyramid
    for (int col = 0; col < 2 * row + 1; col++) {
      cout << " ";
    }

    // inverted half pyramid 2
    for (int col = 0; col < n - row; col++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int row = 0; row < n; row++) {
    // pyramid 1
    for (int col = 0; col < row + 1; col++) {
      cout << "*";
    }

    // inverted full pyramid
    for (int col = 0; col < 2 * n - 2 * row - 1; col++) {
      cout << " ";
    }

    // half pyramid 2
    for (int col = 0; col < row + 1; col++) {
      cout << "*";
    }
    cout << endl;
  }
  // int m;
  // cin >> m;
  // for (int row = 0; row < m; row++) {
  //   // spaces
  //   for (int col = 0; col < m - row - 1; col++) {
  //     cout << " ";
  //   }
  //   // stars
  //   for (int col = 0; col < row + 1; col++) {
  //     if (col == 0 || col == row) {
  //       cout << "* ";
  //     } else
  //       cout << "  ";
  //   }
  //   cout << endl;
  // }
  // for (int row = 0; row < m; row++) {
  //   // spaces
  //   for (int col = 0; col < row; col++) {
  //     cout << " ";
  //   }
  //   // stars
  //   int totalCol = m - row;
  //   for (int col = 0; col < totalCol; col++) {
  //     if (col == 0 || col == totalCol - 1) {
  //       cout << "* ";
  //     } else {
  //       cout << "  ";
  //     }
  //   }
  //   cout << endl;
  // }
  // return 0;
}
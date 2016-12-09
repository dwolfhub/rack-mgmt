#include <iostream>

using namespace std;


bool is_word_possible(string word, string tiles) {
    bool has_tile, has_blanks;

    for (char& c : word) {
        has_tile = has_blanks = false;

        for (char& tile : tiles) {
            cout << tile;
            if (tile == c) {
                tile = NULL;
                has_tile = true;
                break;
            } else if (!has_blanks && tile == '?') {
                has_blanks = true;
            }
        }

        if (!has_tile) {
            if (has_blanks) {
                for (char& tile : tiles) {
                    if (tile == '?') {
                        tile = NULL;
                        has_tile = true;
                        break;
                    }
                }
            }

            if (!has_tile) {
                return false;
            }
        }
    }

    return true;
}


int main() {
    string tiles, word;

    cout << "Enter exactly 7 letter tiles with no spaces" << endl;
    cin >> tiles;

    if (tiles.length() != 7) {
        cout << "ERROR! Please enter exactly 7 tiles";
        return 1;
    }

    cout << "Enter word" << endl;
    cin >> word;

    if (is_word_possible(word, tiles)) {
        return 0;
    }

    return 1;
}
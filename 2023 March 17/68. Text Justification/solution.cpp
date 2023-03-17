class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector <string> lines;
        
        string line = "";
        for (string word : words) {
            if ( line.length() + word.length() <= maxWidth ) {
                line += word + " ";
            }
            else {
                lines.push_back(line);
                line = word + " ";
            }
        }
        lines.push_back(line);
        
        for (int i=0; i<lines.size(); i++) {
            lines[i].pop_back();
            
            if (i == lines.size()-1) {
                lines[i].insert(lines[i].size(), string(maxWidth-lines[i].length(), ' '));
            }
            else {
            
                int spaceCount = count(lines[i].begin(), lines[i].end(), ' ');

                if ( spaceCount ) {

                    int remainingSpaces = maxWidth - lines[i].length();
                    int afterEach = remainingSpaces / spaceCount;
                    remainingSpaces %= spaceCount;

                    for(int j=0; j<maxWidth; j++) {
                        if( lines[i][j] == ' ') {
                            int tmp = afterEach;
                            if(remainingSpaces) {
                                tmp++;
                                remainingSpaces--;
                            }
                            lines[i].insert(j, string(tmp, ' '));
                            j += tmp;
                        }
                    }
                }
                else {
                    lines[i].insert(lines[i].length(), string(maxWidth - lines[i].length(), ' '));
                }
            }
        }
        return lines;
    }
};

class Solution
{
public:
    string getHint(string secret, string guess)
    {

        map<char, int> count;
        int cow = 0, bull = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            count[secret[i]]++;
        }
        for (int i = 0; i < guess.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bull++;
                count[guess[i]]--;
                if (count[guess[i]] == 0)
                {
                    count.erase(guess[i]);
                }
            }
            else
            {
                continue;
            }
        }
        for (int i = 0; i < guess.size(); i++)
        {
            if (secret[i] != guess[i])
            {
                if (count.find(guess[i]) != count.end())
                {
                    cow++;
                    count[guess[i]]--;
                    if (count[guess[i]] == 0)
                    {
                        count.erase(guess[i]);
                    }
                }
            }
            else
            {
                continue;
            }
        }
        string answer = "";
        return answer += to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;

/**
 * http://www.lintcode.com/zh-cn/problem/mini-twitter/-501-迷你推特
 */
 /**
 * Definition of Tweet:
 */
class Tweet {
public:
    int id;
    int user_id;
    string text;
    static int count;
    static Tweet create(int user_id, string tweet_text) {
        // This will create a new tweet object,
        // and auto fill id
        Tweet *t = new Tweet();
        t->id = 0;
        t->user_id = user_id;
        t->text = tweet_text;
        return *t;
    }
};

class MiniTwitter {
private:
    vector<Tweet> Tweets;               // 总Twitter列表
    map<int, set<int>> follows;         // 用户关注列表

public:
    MiniTwitter() {
        // initialize your data structure here.
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        // Write your code here
        // 将用户自身加入其关注列表
        follows[user_id].insert(user_id);
        // 新建 twitter
        Tweet t = Tweet::create(user_id, tweet_text);
        Tweets.push_back(t);
        return t;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        vector<Tweet> result;
        // 在总 twitter 表中查找用户自己发布的 Twitter，最多十条
        for (int i = Tweets.size() - 1, count = 0; i >= 0 && count < 10; i--) {
            if (follows[user_id].find(Tweets[i].user_id) != follows[user_id].end()) {
                result.push_back(Tweets[i]);
                count++;
            }
        }
        return result;
    }

    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        // Write your code here
        vector<Tweet> result;
        // 在总 twitter 表中查找用户关注的用户发布的 Twitter，最多十条
        for (int i = Tweets.size() - 1, count = 0; i >= 0 && count < 10; i--) {
            if (Tweets[i].user_id == user_id) {
                result.push_back(Tweets[i]);
                count++;
            }
        }
        return result;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        // 新建关注关系
        follows[from_user_id].insert(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        // 取消关注关系
        follows[from_user_id].erase(to_user_id);
    }

    void display(string s) {
        for (int i = 0; i < s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }

    void display(Tweet t) {
        cout << "id:" << t.id << endl;
        cout << "user:" << t.user_id << endl;
        cout << "test:";
        display(t.text);
        cout << endl;
    }

    void display(vector<Tweet> &nums) {
        vector<Tweet>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            display(*i);
        }
        cout << endl;
    }
};

int main()
{
    MiniTwitter mt;

    mt.display(mt.postTweet(1, "LintCode is Good 1 1"));
    /*mt.display(mt.getNewsFeed(1));
    mt.display(mt.getTimeline(1));
    mt.follow(2, 1);
    mt.display(mt.getNewsFeed(2));
    mt.unfollow(2, 1);
    mt.display(mt.getNewsFeed(2));*/


    return 0;
}
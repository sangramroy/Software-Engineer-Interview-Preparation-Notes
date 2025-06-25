#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory> // For shared_ptr
using namespace std;

// Abstract Subscriber
class Subscriber {
public:
    virtual void update(const string& videoTitle) = 0;
    virtual ~Subscriber() {}
};

// Publisher Interface
class Publisher {
public:
    virtual void subscribe(shared_ptr<Subscriber> sub) = 0;
    virtual void unsubscribe(shared_ptr<Subscriber> sub) = 0;
    virtual void publish(const string& videoTitle) = 0;
    virtual ~Publisher() {}
};

// Concrete Publisher: YouTubeChannel
class YouTubeChannel : public Publisher {
    vector<shared_ptr<Subscriber>> subscribers;

public:
    void subscribe(shared_ptr<Subscriber> sub) override {
        subscribers.push_back(sub);
    }

    void unsubscribe(shared_ptr<Subscriber> sub) override {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), sub), subscribers.end());
    }

    void publish(const string& videoTitle) override {
        cout << "\n🎥 [YouTubeChannel] Uploaded: " << videoTitle << endl;
        for (auto& sub : subscribers) {
            sub->update(videoTitle);
        }
    }
};

// Concrete Subscriber: User
class User : public Subscriber {
    string name;

public:
    User(const string& username) : name(username) {}

    void update(const string& videoTitle) override {
        cout << "📢 " << name << " got notified: New video - \"" << videoTitle << "\"\n";
    }
};

int main() {
    YouTubeChannel channel;

    // Dynamically created users using shared_ptr
    auto u1 = make_shared<User>("Alice");
    auto u2 = make_shared<User>("Bob");
    auto u3 = make_shared<User>("Charlie");

    channel.subscribe(u1);
    channel.subscribe(u2);

    channel.publish("Observer Pattern Explained in C++");

    channel.unsubscribe(u1);   // Alice unsubscribes
    channel.subscribe(u3);     // Charlie subscribes

    channel.publish("Top 10 C++ Interview Questions");

    return 0;
}
#include <iostream>

using namespace std;

//void SendSms(const string& number, const string& message);
//void SendEmail(const string& email, const string& message);

class INotifier{
public:
    virtual void Notify(const string& message) = 0;
};

class SmsNotifier: public INotifier{
public:
    SmsNotifier(string tel):tel_(tel){}
    void Notify(const string &message) override{
        SendSms(tel_, message);
    }
private:
    string tel_;
};

class EmailNotifier: public INotifier{
public:
    EmailNotifier(string email):email_(email){}

    void Notify(const string &message) override{
        SendEmail(email_, message);
    }
private:
    string email_;

};

//void Notify(INotifier& notifier, const string& message) {
//  notifier.Notify(message);
//}


//void SendSms(const string& number, const string& message) {
//  cout << "Send '" << message << "' to number " << number << endl;
//}
//
//void SendEmail(const string& email, const string& message) {
//  cout << "Send '" << message << "' to e-mail "  << email << endl;
//}
//
//
//int main() {
//  SmsNotifier sms{"+7-495-777-77-77"};
//  EmailNotifier email{"na-derevnyu@dedushke.ru"};
//
//  Notify(sms, "I have White belt in C++");
//  Notify(email, "And want a Yellow one");
//  return 0;
//}
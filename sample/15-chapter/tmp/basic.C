#include <iostream>
#include <string>
using namespace std;

class User {
  public :
    int userNo_;
    string userId_;
    string userName_;
};

class Member {
  public :
    void List(int pageNo, int sortType) {
      // -- sortType ���� Sorting �� ȸ�� ��� ������ ǥ��
    }
    void Join(User& aUser) {
      // -- aUser�� ȸ������ ����
    }
    void Withdraw(User& aUser) {
      // -- aUser�� ȸ������ ����
    }
    void JoinApply(User& aUser) {
      // -- ȸ�� ��� ��û
    }
    void ApplyList(int pageNo, int sortType) {
      // -- ȸ�� ��� ��û�� �̿��� ��� ǥ��
    }
};

class BBS {
  pubilc : 
    virtual void List(int pageNo) = 0;
    virtual void Read(int bbsNo) = 0;
    virtual void Write() = 0;
    virtual void Remove(int bbsNo) = 0;
};

class FreeBBS : public BBS {
  public : 
    void List(int pageNo) {
      // -- pageNo ��ġ�� �Խù� ����Ʈ�� �����ش�.
    }
    void Read(int bbsNo) {
    }
    void Write() {
    }
    void Remove(int bbsNo) {
    }
};
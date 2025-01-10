#include <iostream>
#include <string>

class Character {
private:
    // ��� ����
    std::string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int experience;
    int gold;

    // �̱��� �ν��Ͻ�
    static Character* instance;

    // �����ڸ� private���� ����
    Character(const std::string& name)
        : name(name), level(1), health(200), maxHealth(200),
        attack(30), experience(0), gold(0) {
    }

public:
    // �̱��� �ν��Ͻ��� ��ȯ�ϴ� �޼ҵ�
    static Character* getInstance(const std::string& name = "") {
        if (instance == nullptr) {
            instance = new Character(name);
        }
        return instance;
    }

    // ĳ���� ���� ��� �޼ҵ�
    void displayStatus() const {
        std::cout << "�̸�: " << name
            << ", ����: " << level
            << ", ü��: " << health << "/" << maxHealth
            << ", ���ݷ�: " << attack
            << ", ����ġ: " << experience
            << ", ���: " << gold << std::endl;
    }
};

// �̱��� �ν��Ͻ� �ʱ�ȭ
Character* Character::instance = nullptr;

// ���� �Լ�
int main() {
    std::string playerName;

    // ����ڷκ��� �̸� �Է� �ޱ�
    std::cout << "ĳ������ �̸��� �Է��ϼ���: ";
    std::getline(std::cin, playerName);

    // ĳ���� ����
    Character* player = Character::getInstance(playerName);

    // ���� ���
    player->displayStatus();

    return 0;
}

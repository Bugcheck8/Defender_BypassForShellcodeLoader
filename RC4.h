#include <stdio.h>
#include <Windows.h>

class RC4
{

public:
	RC4();

	void rc4_init(unsigned char *key, unsigned long Len);

	// ��/�� ��
	void do_crypt(unsigned char *Data, unsigned long Len);

private:

	int m_box[256]; // �ԳƼ����е��û��� S��
	int m_index_i;
	int m_index_j;
};
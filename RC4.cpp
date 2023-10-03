#include "RC4.h"

RC4::RC4()
{
	m_index_i = 0;
	m_index_j = 0;
}

// ��ʼ���㷨
void RC4::rc4_init(unsigned char *key, unsigned long Len)
{
	if (key == NULL || Len == 0)
	{
		printf("rc4 key or len is 0, return! ");
		return;
	}

	// forѭ����0��255�Ļ����ظ���Ԫ��װ��S��
	for (int i = 0; i < 256; i++) {
		m_box[i] = i;
	}

	// forѭ��������Կ����S��
	int j = 0;
	unsigned char tmp;
	for (int i = 0; i < 256; i++)
	{
		j = (j + m_box[i] + key[i % Len]) % 256;

		tmp = m_box[i];
		m_box[i] = m_box[j]; //����m_box[i]��m_box[j]
		m_box[j] = tmp;
	}
}

void RC4::do_crypt(unsigned char *Data, unsigned long Len)
{
	// ÿ�յ�һ���ֽڣ��ͽ���whileѭ����ͨ��һ�����㷨��(a),(b)����λS���е�һ��Ԫ�أ����������ֽ���򣬵õ�k��ѭ���л��ı���S�У�(c)�����������������ģ�����ľ������ģ��������������ģ�����ľ������ġ�
	unsigned char tmp;
	for (unsigned long k = 0; k < Len; k++)
	{
		m_index_i = (m_index_i + 1) % 256;    // a
		m_index_j = (m_index_j + m_box[m_index_i]) % 256; // b

		tmp = m_box[m_index_i];
		m_box[m_index_i] = m_box[m_index_j]; //����m_box[x]��m_box[y]
		m_box[m_index_j] = tmp;

		// ����α�����
		int r = (m_box[m_index_i] + m_box[m_index_j]) % 256;
		Data[k] ^= m_box[r];
	}

}

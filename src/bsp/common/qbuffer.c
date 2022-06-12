#include "qbuffer.h"


void qbufferInit(void)
{

}

bool qbufferCreate(qbuffer_t *p_node,uint8_t *p_buf, uint32_t length)
{
	bool ret = true;

	p_node->in    = 0;       // rear (인큐)
	p_node->out   = 0;       // front (아웃큐)
	p_node->len   = length;
	p_node->p_buf = p_buf;   // 버퍼가 "널" 일때 인덱스만 사용

	return ret;

}

bool qbufferWrite(qbuffer_t *p_node,uint8_t *p_data, uint32_t length)
{

	bool ret = true;
	uint32_t next_in;

	for(int i=0; i<length; i++)
	{
		next_in = (p_node->in + 1) % p_node->len;

		if(next_in != p_node->out)  // 다음 공간이 비었을 경우, 같은 경우는 버퍼가 꽉찬거임
	    {
			if(p_node->p_buf != NULL)
			{
				p_node->p_buf[p_node->in] = p_data[i]; // 현재 인덱스에 데이터 삽입
			}
			p_node->in = next_in; // 버퍼가 널일때 인덱스만 관리
		}
		else{
			ret = false;  // 버퍼가 찼을 경우 빠져 나옴
			break;
		}
	}


	return ret;
}

bool qbufferRead(qbuffer_t *p_node,uint8_t *p_data, uint32_t length)
{
	bool ret = true;

	for(int i=0; i<length; i++)
	{
		if(p_node->p_buf != NULL)
		{
			p_data[i] = p_node->p_buf[p_node->out];
		}

		if(p_node->out != p_node->in)
		{
		    p_node->out = (p_node->out+1) % p_node->len;
		}
		else
		{
			ret = false;
			break;
		}
	}
     return ret;
}

uint32_t qbufferAvailable(qbuffer_t *p_node)
{
	uint32_t ret;

	ret = (p_node->in - p_node->out) % p_node->len;

	return ret;
}

void qbufferFlush(qbuffer_t *p_node)
{
	p_node->in = 0;
	p_node->out = 0;
}

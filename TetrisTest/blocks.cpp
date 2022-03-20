#include "blocks.h"

void blocks::setCoordinate(int x, int y, int width, int hight) {
	m_x = x;
	m_y = y;
	m_width = width;
	m_hight = hight;
}

int blocks::getState() {
	return state;//��ʾ���ǵ�ǰ��״�ĺ���
}

/***************************************����***************************************/
void OneGlyph::CreateBlocks(QPainter &painter,int mswitch)
{
	painter.setRenderHint(QPainter::Antialiasing, true);
	// ���û�����ɫ�����
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// ���û�ˢ��ɫ
	painter.setBrush(QColor(255, 160, 90));
	switch (mswitch)
	{
	default://case 0 ����
		painter.drawRect(m_x , m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width * 3, m_y, m_width, m_hight);

		state = 0;
		break;
	case 1: //case 2 ���� 
		painter.drawRect(m_x , m_y, m_width, m_hight);
		painter.drawRect(m_x , m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x , m_y + m_hight * 2, m_width, m_hight);
		painter.drawRect(m_x , m_y + m_hight * 3, m_width, m_hight);

		state = 1;
		break;
	}
}

bool OneGlyph::isInrange(int mswitch) {

	if (grid.empty())
	{
		return false;
	}
	//bool x_isInrange = grid_x >= 0 && grid_x < grid.size();//x�Ƿ�Խ��
	//bool y_isInrange = grid_y >= 0 && grid_y+4 < grid[grid.size() - 1].size();//�����Ƿ�Խ��
	//bool iscollision = 
	//	grid[grid_x][grid_y].isfull || 
	//	grid[grid_x][grid_y+1].isfull || 
	//	grid[grid_x][grid_y+2].isfull || 
	//	grid[grid_x][grid_y+3].isfull;//�Ƿ�����ײ
	if (mswitch==0)
	{
		return (grid_x >= 0 && grid_x + 3 < grid.size())
			&& (grid_y >= 0 && grid_y  < grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x+1][grid_y].isfull ||
					grid[grid_x+2][grid_y].isfull ||
					grid[grid_x+3][grid_y].isfull)
				);
	}
	else {
		return (grid_x >= 0 && grid_x < grid.size())
			&& (grid_y >= 0 && grid_y + 3< grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x][grid_y + 1].isfull ||
					grid[grid_x][grid_y + 2].isfull ||
					grid[grid_x][grid_y + 3].isfull)
				);
	}

}

void OneGlyph::setFull(int mswitch) {

	if (grid.empty())
	{
		return;
	}
	if (mswitch == 0)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x + 2][grid_y].isfull = true;
		grid[grid_x + 3][grid_y].isfull = true;
			
	}
	else {
		grid[grid_x][grid_y].isfull = true;;
		grid[grid_x][grid_y + 1].isfull = true;;
		grid[grid_x][grid_y + 2].isfull = true;;
		grid[grid_x][grid_y + 3].isfull = true;;
	}

}

void OneGlyph::rotate(int &block_x,int &block_y,int &swicth) {
	if (getState() == 0)//�ɺ����
	{
		std::vector<int>changex = { 2,2,2,2 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { -2,-1,0,1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(1))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 1;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 1)//�������
	{
		std::vector<int>changex = { -2,-1,-3,0 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 2,2,2,2 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(0))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 0;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	//MainGroup.clear();
}


/***************************************����***************************************/
void SevenGlyph::CreateBlocks(QPainter &painter, int mswitch)//��֤����״�����Ͻ�����
{
	painter.setRenderHint(QPainter::Antialiasing, true);
	// ���û�����ɫ�����
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// ���û�ˢ��ɫ
	painter.setBrush(QColor(255, 100, 60));
	switch (mswitch)
	{
	default://Ĭ��״̬��Ҳ���ǳ�ʼ��״
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y + m_hight, m_width, m_hight);
		state = 0;
		break;

	case 1://˳ʱ����ת90
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight*2, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		state = 1;
		break;
	case 2://˳ʱ����ת180
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y , m_width, m_hight);
		painter.drawRect(m_x + m_width*2, m_y , m_width, m_hight);
		painter.drawRect(m_x + m_width*2, m_y + m_hight, m_width, m_hight);
		state = 2;
		break;
		
	case 3://˳ʱ����ת270
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight*2, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight*2, m_width, m_hight);
		state = 3;
		break;

	case 4://Ĭ��״̬��Ҳ���ǳ�ʼ��״�ľ���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y - m_hight, m_width, m_hight);
		state = 4;
		break;

	case 5://˳ʱ����ת90������
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight * 2, m_width, m_hight);
		state = 5;
		break;
	case 6://˳ʱ����ת180������
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y, m_width, m_hight);
		state = 6;
		break;

	case 7://˳ʱ����ת270������
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight * 2, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight * 2, m_width, m_hight);
		state = 7;
		break;
	}
}

bool SevenGlyph::isInrange(int mswitch) {

	if (grid.empty())
	{
		return false;
	}

	if (mswitch == 0)
	{
		return (grid_x >= 0 && grid_x + 2 < grid.size())
			&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
			&& (!(grid[grid_x][grid_y].isfull ||
					grid[grid_x][grid_y+1].isfull ||
					grid[grid_x + 1][grid_y+1].isfull ||
					grid[grid_x + 2][grid_y+1].isfull)
				);
	}
	else if (mswitch == 1) {
		return (grid_x >= 0 && grid_x + 1 < grid.size())
			&& (grid_y >= 0 && grid_y + 2 < grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x][grid_y + 1].isfull ||
					grid[grid_x][grid_y + 2].isfull ||
					grid[grid_x + 1][grid_y].isfull)
				);
	}
	else if (mswitch == 2) {
		return (grid_x >= 0 && grid_x + 2 < grid.size())
			&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x + 1][grid_y].isfull ||
					grid[grid_x + 2][grid_y].isfull ||
					grid[grid_x + 2][grid_y + 1].isfull)
				);
	}
	else if (mswitch == 3)
	{
		return (grid_x - 1 >= 0 && grid_x  < grid.size())
			&& (grid_y >= 0 && grid_y + 2 < grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x][grid_y + 1].isfull ||
					grid[grid_x][grid_y + 2].isfull ||
					grid[grid_x - 1][grid_y + 2].isfull)
				);
	}
	
	/*����*/
	else if (mswitch == 4)
	{
		return (grid_x >= 0 && grid_x + 2 < grid.size())
			&& (grid_y - 1 >= 0 && grid_y < grid[grid.size() - 1].size())
			&& (!(grid[grid_x][grid_y].isfull ||
			grid[grid_x + 1][grid_y].isfull ||
			grid[grid_x + 2][grid_y].isfull ||
			grid[grid_x + 2][grid_y - 1].isfull)
			);
	}
	else if (mswitch == 5) {
		return (grid_x >= 0 && grid_x + 1 < grid.size())
			&& (grid_y >= 0 && grid_y + 2 < grid[grid.size() - 1].size())
			&& (!
			(grid[grid_x][grid_y].isfull ||
			grid[grid_x + 1][grid_y].isfull ||
			grid[grid_x + 1][grid_y + 1].isfull ||
			grid[grid_x + 1][grid_y + 2].isfull)
			);
	}
	else if (mswitch == 6) {
		return (grid_x >= 0 && grid_x + 2 < grid.size())
			&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
			&& (!
			(grid[grid_x][grid_y].isfull ||
			grid[grid_x + 1][grid_y].isfull ||
			grid[grid_x][grid_y + 1].isfull ||
			grid[grid_x + 2][grid_y].isfull)
			);
	}
	else
	{
		return (grid_x >= 0 && grid_x + 1 < grid.size())
			&& (grid_y >= 0 && grid_y + 2 < grid[grid.size() - 1].size())
			&& (!
			(grid[grid_x][grid_y].isfull ||
			grid[grid_x][grid_y + 1].isfull ||
			grid[grid_x][grid_y + 2].isfull ||
			grid[grid_x + 1][grid_y + 2].isfull)
			);
	}

}
void SevenGlyph::setFull(int mswitch) {

	if (grid.empty())
	{
		return;
	}
	if (mswitch == 0)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x + 1][grid_y + 1].isfull = true;
		grid[grid_x + 2][grid_y + 1].isfull = true;

	}
	else if (mswitch == 1) {
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x][grid_y + 2].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;

	}
	else if (mswitch == 2) {
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x + 2][grid_y].isfull = true;
		grid[grid_x + 2][grid_y + 1].isfull = true;

	}
	else if (mswitch==3)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x][grid_y + 2].isfull = true;
		grid[grid_x - 1][grid_y + 2].isfull = true;

	}
	
	/*����*/
	else if (mswitch == 4)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x + 2][grid_y].isfull = true;
		grid[grid_x + 2][grid_y - 1].isfull = true;

	}
	else if (mswitch == 5) {
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x + 1][grid_y + 1].isfull = true;
		grid[grid_x + 1][grid_y + 2].isfull = true;

	}
	else if (mswitch == 6) {
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x + 2][grid_y].isfull = true;
	}
	else
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x][grid_y + 2].isfull = true;
		grid[grid_x + 1][grid_y + 2].isfull = true;

	}
}
void SevenGlyph::rotate(int &block_x, int &block_y, int &swicth) {
	if (getState() == 0)//�ɳ�ʼ˳ʱ����ת90
	{
		std::vector<int>changex = { 1,0,2,1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 0,0,0,1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(1))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 1;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 1)//������ת90
	{
		std::vector<int>changex = { -1,-2,0 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 1,1,1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(2))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 2;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 2)//������ת90
	{
		std::vector<int>changex = { 1,0,2 ,1};//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { -1,-1,-1,0};

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(3))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 3;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 3)//������ת90
	{
		std::vector<int>changex = { -1,-2,1,-1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 0,0,0,-1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(0))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 0;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}

	else if (getState() == 4)//����ʱ����ת90
	{
		std::vector<int>changex = { 0, 0, -1, 1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { -1, 0, -1, -1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(5))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 5;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 5)//������ת90
	{
		std::vector<int>changex = { 0, -1, 1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 1, 1, 1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(6))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 6;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 6)//������ת90
	{
		std::vector<int>changex = { 1, 0, 2, 1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { -1, -1, -1, 0 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(7))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 7;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 7)//������ת90
	{
		std::vector<int>changex = { -1, -2, 0, -1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 1, 1, 1, 2 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(4))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 4;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}

}

void SevenGlyph::overturn(int &block_x, int &block_y, int &swicth){
	if (getState() == 0)//�ɳ�ʼ˳ʱ����ת90
	{
		grid_x = grid_x;
		grid_y = grid_y + 1;
		if (isInrange(4))
		{
			block_x = grid_x;
			block_y = grid_y;
			swicth = 4;
			return;
		}
		grid_x = grid_x;
		grid_y = grid_y - 1;
	}
	else if (getState() == 1)//������ת90
	{
		if (isInrange(5))
		{
			swicth = 5;
			return;
		}
	}
	else if (getState() == 2)//������ת90
	{
		if (isInrange(6))
		{
			swicth = 6;
			return;
		}
	}
	else if (getState() == 3)//������ת90
	{
		if (isInrange(7))
		{
			swicth = 7;
			return;
		}
	}

	else if (getState() == 4)//����ʱ����ת90
	{
		grid_x = grid_x;
		grid_y = grid_y - 1;
		if (isInrange(0))
		{
			block_x = grid_x;
			block_y = grid_y;
			swicth = 0;
			return;
		}
		grid_x = grid_x;
		grid_y = grid_y + 1;
	}
	else if (getState() == 5)//������ת90
	{
		if (isInrange(1))
		{
			swicth = 1;
			return;
		}
	}
	else if (getState() == 6)//������ת90
	{
		if (isInrange(2))
		{
			swicth = 2;
			return;
		}
	}
	else if (getState() == 7)//������ת90
	{
		if (isInrange(3))
		{
			swicth = 3;
			return;
		}
	}
}


/***************************************����***************************************/
void SoilGlyph::CreateBlocks(QPainter &painter, int mswitch) {
	painter.setRenderHint(QPainter::Antialiasing, true);
	// ���û�����ɫ�����
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// ���û�ˢ��ɫ
	painter.setBrush(QColor(150, 100, 60));

	switch (mswitch)
	{
	default://Ĭ��״̬��Ҳ���ǳ�ʼ��״��������ķ�����Ϊ�ο���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		state = 0;
		break;

	case 1://˳ʱ����ת90 ������ķ�����Ϊ�ο���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight * 2, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		state = 1;
		break;
	case 2://˳ʱ����ת180 ����ߵķ�����Ϊ�ο���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width , m_y + m_hight, m_width, m_hight);
		state = 2;
		break;

	case 3://˳ʱ����ת270
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight * 2, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
		state = 3;
		break;
	}
}
bool SoilGlyph::isInrange(int mswitch) {

	if (grid.empty())
	{
		return false;
	}
	//bool x_isInrange = grid_x >= 0 && grid_x < grid.size();//x�Ƿ�Խ��
	//bool y_isInrange = grid_y >= 0 && grid_y+4 < grid[grid.size() - 1].size();//�����Ƿ�Խ��
	//bool iscollision = 
	//	grid[grid_x][grid_y].isfull || 
	//	grid[grid_x][grid_y+1].isfull || 
	//	grid[grid_x][grid_y+2].isfull || 
	//	grid[grid_x][grid_y+3].isfull;//�Ƿ�����ײ
	if (mswitch == 0)
	{
		return (grid_x -1 >= 0 && grid_x + 1 < grid.size())
			&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
			&& (!(grid[grid_x][grid_y].isfull ||
				grid[grid_x][grid_y + 1].isfull ||
				grid[grid_x + 1][grid_y + 1].isfull ||
				grid[grid_x - 1][grid_y + 1].isfull)
				);
	}
	else if (mswitch == 1) {
		return (grid_x >= 0 && grid_x + 1 < grid.size())
			&& (grid_y >= 0 && grid_y + 2 < grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x][grid_y + 1].isfull ||
					grid[grid_x][grid_y + 2].isfull ||
					grid[grid_x + 1][grid_y + 1].isfull)
				);
	}
	else if (mswitch == 2) {
		return (grid_x >= 0 && grid_x + 2 < grid.size())
			&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x + 1][grid_y].isfull ||
					grid[grid_x + 2][grid_y].isfull ||
					grid[grid_x + 1][grid_y + 1].isfull)
				);
	}
	else
	{
		return (grid_x - 1 >= 0 && grid_x < grid.size())
			&& (grid_y >= 0 && grid_y + 2 < grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x][grid_y + 1].isfull ||
					grid[grid_x][grid_y + 2].isfull ||
					grid[grid_x - 1][grid_y + 1].isfull)
				);
	}

}
void SoilGlyph::setFull(int mswitch) {

	if (grid.empty())
	{
		return;
	}
	if (mswitch == 0)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x + 1][grid_y + 1].isfull = true;
		grid[grid_x - 1][grid_y + 1].isfull = true;
	}
	else if (mswitch == 1) {
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x][grid_y + 2].isfull = true;
		grid[grid_x + 1][grid_y + 1].isfull = true;

	}
	else if (mswitch == 2) {
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x + 2][grid_y].isfull = true;
		grid[grid_x + 1][grid_y + 1].isfull = true;

	}
	else
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x][grid_y + 2].isfull = true;
		grid[grid_x - 1][grid_y + 1].isfull = true;
	}
}
void SoilGlyph::rotate(int &block_x, int &block_y, int &swicth) {
	if (getState() == 0)//�ɳ�ʼ˳ʱ����ת90
	{
		std::vector<int>changex = { 0 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 0 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(1))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 1;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 1)//������ת90
	{
		std::vector<int>changex = { -1,0 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 1,1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(2))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 2;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 2)//������ת90
	{
		std::vector<int>changex = { 1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { -1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(3))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 3;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 3)//������ת90
	{
		std::vector<int>changex = { 0,-1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 0,0 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(0))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 0;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
}

/***************************************̨����***************************************/
void StepGlyph::CreateBlocks(QPainter &painter, int mswitch) {
	painter.setRenderHint(QPainter::Antialiasing, true);
	// ���û�����ɫ�����
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// ���û�ˢ��ɫ
	painter.setBrush(QColor(100, 201, 201));

	switch (mswitch)
	{
	default://Ĭ��״̬��Ҳ���ǳ�ʼ��״��������ķ�����Ϊ�ο���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight * 2, m_width, m_hight);
		state = 0;
		break;

	case 1://˳ʱ����ת90 ������ķ�����Ϊ�ο���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		state = 1;
		break;

	case 2://˳ʱ����ת90 ������ķ�����Ϊ�ο���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight * 2, m_width, m_hight);
		state = 2;
		break;

	case 3://˳ʱ����ת90 ������ķ�����Ϊ�ο���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y + m_hight, m_width, m_hight);
		state = 3;
		break;
	}


}
bool StepGlyph::isInrange(int mswitch) {

	if (grid.empty())
	{
		return false;
	}
	if (mswitch == 0)
	{
		return (grid_x >= 0 && grid_x + 1 < grid.size())
			&& (grid_y >= 0 && grid_y + 2 < grid[grid.size() - 1].size())
			&& (!(grid[grid_x][grid_y].isfull ||
				grid[grid_x][grid_y + 1].isfull ||
				grid[grid_x + 1][grid_y + 1].isfull ||
				grid[grid_x + 1][grid_y + 2].isfull)
				);
	}
	else if (mswitch ==1)
	{
		return (grid_x - 1 >= 0 && grid_x + 1 < grid.size())
			&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
			&& (!
				(grid[grid_x][grid_y].isfull ||
					grid[grid_x + 1][grid_y].isfull ||
					grid[grid_x][grid_y + 1].isfull ||
					grid[grid_x - 1][grid_y + 1].isfull)
				);
	}
	else if (mswitch == 2)
	{
		return (grid_x - 1 >= 0 && grid_x < grid.size())
			&& (grid_y >= 0 && grid_y + 2 < grid[grid.size() - 1].size())
			&& (!
			(grid[grid_x][grid_y].isfull ||
			grid[grid_x][grid_y + 1].isfull ||
			grid[grid_x - 1][grid_y + 1].isfull ||
			grid[grid_x - 1][grid_y + 2].isfull)
			);
	}
	else 
	{
		return (grid_x >= 0 && grid_x + 2 < grid.size())
			&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
			&& (!
			(grid[grid_x][grid_y].isfull ||
			grid[grid_x + 1][grid_y].isfull ||
			grid[grid_x + 1][grid_y + 1].isfull ||
			grid[grid_x + 2][grid_y + 1].isfull)
			);
	}
}

void StepGlyph::setFull(int mswitch) {
	if (grid.empty())
	{
		return;
	}
	if (mswitch == 0)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x + 1][grid_y + 1].isfull = true;
		grid[grid_x + 1][grid_y + 2].isfull = true;
	}
	else if (mswitch==1)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x - 1][grid_y + 1].isfull = true;
	}
	else if (mswitch == 2)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x - 1][grid_y + 1].isfull = true;
		grid[grid_x - 1][grid_y + 2].isfull = true;
	}
	else 
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x + 1][grid_y + 1].isfull = true;
		grid[grid_x + 2][grid_y + 1].isfull = true;
	}
}

void StepGlyph::rotate(int &block_x, int &block_y, int &swicth) {
	if (getState() == 0)//�ɳ�ʼ˳ʱ����ת90
	{
		std::vector<int>changex = { 1,0 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 0,0 };
		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(1))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 1;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 1)//������ת90
	{
		std::vector<int>changex = { -1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 0 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(0))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 0;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}	




	else if (getState() == 2)//�ɳ�ʼ˳ʱ����ת90
	{
		std::vector<int>changex = { -2, 1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 1, 1 };
		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(3))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 3;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	else if (getState() == 3)//������ת90
	{
		std::vector<int>changex = { 2, -1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { -1, -1 };

		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(2))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 2;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
}

void StepGlyph::overturn(int &block_x, int &block_y, int &swicth){
	if (getState() == 0)//�ɳ�ʼ����
	{
		grid_x = grid_x + 1;
		grid_y = grid_y;
		if (isInrange(2))
		{
			block_x = grid_x;
			block_y = grid_y;
			swicth = 2;
			return;
		}
		grid_x = grid_x-1;
		grid_y = grid_y;
	}
	else if (getState() == 1)//�ɳ�ʼ90��ת����
	{
		grid_x = grid_x - 1;
		grid_y = grid_y;
		if (isInrange(3))
		{
			block_x = grid_x;
			block_y = grid_y;
			swicth = 3;
			return;
		}
		grid_x = grid_x + 1;
		grid_y = grid_y;
	}


	else if (getState() == 2)
	{
		grid_x = grid_x - 1;
		grid_y = grid_y;
		if (isInrange(0))
		{
			block_x = grid_x;
			block_y = grid_y;
			swicth = 0;
			return;
		}
		grid_x = grid_x + 1;
		grid_y = grid_y;
	}
	else if (getState() == 3)//������ת90
	{
		grid_x = grid_x + 1;
		grid_y = grid_y;
		if (isInrange(1))
		{
			block_x = grid_x;
			block_y = grid_y;
			swicth = 1;
			return;
		}
		grid_x = grid_x - 1;
		grid_y = grid_y;
	}

}


/***************************************����***************************************/
void FieldGlyph::CreateBlocks(QPainter &painter, int mswitch) {
	painter.setRenderHint(QPainter::Antialiasing, true);
	// ���û�����ɫ�����
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// ���û�ˢ��ɫ
	painter.setBrush(QColor(231, 190, 231));

	switch (mswitch)
	{
	default://Ĭ��״̬��Ҳ���ǳ�ʼ��״��������ķ�����Ϊ�ο���
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		state = 0;
		break;

	//case 1://˳ʱ����ת90 ������ķ�����Ϊ�ο���
	//	painter.drawRect(m_x, m_y, m_width, m_hight);
	//	painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
	//	painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
	//	painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
	//	state = 1;
	//	break;
	}

	//painter.drawRect(m_x, m_y, m_width, m_hight);

	////painter.setPen(QPen(QColor(0, 160, 230), 2));
	//// ���û�ˢ��ɫ
	////painter.setBrush(QColor(255, 160, 90));
	//painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);

	////painter.setBrush(QColor(255, 160, 90));
	//painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
	//painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
}

bool FieldGlyph::isInrange(int mswitch) {

	if (grid.empty())
	{
		return false;
	}
	if (mswitch == 0)
	{
		return (grid_x >= 0 && grid_x + 1 < grid.size())
			&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
			&& (!(grid[grid_x][grid_y].isfull ||
				grid[grid_x][grid_y + 1].isfull ||
				grid[grid_x + 1][grid_y].isfull ||
				grid[grid_x + 1][grid_y + 1].isfull)
				);
	}
	else
	{
		//return (grid_x - 1 >= 0 && grid_x + 1 < grid.size())
		//	&& (grid_y >= 0 && grid_y + 1 < grid[grid.size() - 1].size())
		//	&& (!
		//		(grid[grid_x][grid_y].isfull ||
		//			grid[grid_x + 1][grid_y].isfull ||
		//			grid[grid_x + 1][grid_y + 1].isfull ||
		//			grid[grid_x - 1][grid_y + 1].isfull)
		//		);
		return false;
	}
}

void FieldGlyph::setFull(int mswitch) {
	if (grid.empty())
	{
		return;
	}
	if (mswitch == 0)
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x + 1][grid_y + 1].isfull = true;
		grid[grid_x + 1 ][grid_y ].isfull = true;
	}
	//else
	//{
	//	grid[grid_x][grid_y].isfull = true;
	//	grid[grid_x + 1][grid_y].isfull = true;
	//	grid[grid_x + 1][grid_y + 1].isfull = true;
	//	grid[grid_x + 2][grid_y + 1].isfull = true;
	//}
}

void FieldGlyph::rotate(int &block_x, int &block_y, int &swicth) {
	if (getState() == 0)//�ɳ�ʼ˳ʱ����ת90
	{
		std::vector<int>changex = { 0};//��������������Ҫת����λ�ã����ȼ��𲽽���
		std::vector<int>changey = { 0};
		for (int i = 0; i < changex.size(); ++i)
		{
			grid_x = grid_x + changex[i];
			grid_y = grid_y + changey[i];
			if (isInrange(1))
			{
				block_x = grid_x;
				block_y = grid_y;
				swicth = 1;
				break;
			}
			grid_x = grid_x - changex[i];
			grid_y = grid_y - changey[i];
		}
	}
	//else if (getState() == 1)//������ת90
	//{
	//	std::vector<int>changex = { -1 };//��������������Ҫת����λ�ã����ȼ��𲽽���
	//	std::vector<int>changey = { 0 };

	//	for (int i = 0; i < changex.size(); ++i)
	//	{
	//		grid_x = grid_x + changex[i];
	//		grid_y = grid_y + changey[i];
	//		if (isInrange(0))
	//		{
	//			block_x = grid_x;
	//			block_y = grid_y;
	//			swicth = 0;
	//			break;
	//		}
	//		grid_x = grid_x - changex[i];
	//		grid_y = grid_y - changey[i];
	//	}
	//}
}


/***************************************��������***************************************/
std::vector<std::vector<OneBlock>>  DrawGrid::CreateGrid( int m_width,int m_high,int col,int row) {
	OneBlock oneblock;
	std::vector<std::vector<OneBlock>> group;
	std::vector<OneBlock>temp;
	{
		float one_block_w = (m_width ) / col;
		float one_block_h = (m_high ) / row;

		for (int i = 0; i < col; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				oneblock.p_start.setX(i*one_block_w );
				oneblock.p_start.setY(j*one_block_h );
				oneblock.w = one_block_w;
				oneblock.h = one_block_h;
				oneblock.isfull = false;
				temp.push_back(oneblock);
			}
			group.push_back(temp);
			temp.clear();
		}
	}
	return group;
}
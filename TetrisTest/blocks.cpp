#include "blocks.h"

void blocks::setCoordinate(int x, int y, int width, int hight) {
	m_x = x;
	m_y = y;
	m_width = width;
	m_hight = hight;
}

int blocks::getState() {
	return state;//表示的是当前形状的横竖
}

/***************************************横条***************************************/
void shape1::CreateBlocks(QPainter &painter,int mswitch)
{
	painter.setRenderHint(QPainter::Antialiasing, true);
	// 设置画笔颜色、宽度
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// 设置画刷颜色
	painter.setBrush(QColor(255, 160, 90));
	switch (mswitch)
	{
	default://case 0 横着
		painter.drawRect(m_x , m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width * 3, m_y, m_width, m_hight);

		state = 0;
		break;
	case 1: //case 2 竖着 
		painter.drawRect(m_x , m_y, m_width, m_hight);
		painter.drawRect(m_x , m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x , m_y + m_hight * 2, m_width, m_hight);
		painter.drawRect(m_x , m_y + m_hight * 3, m_width, m_hight);

		state = 1;
		break;
	}
}

bool shape1::isInrange(int mswitch) {

	if (grid.empty())
	{
		return false;
	}
	//bool x_isInrange = grid_x >= 0 && grid_x < grid.size();//x是否越界
	//bool y_isInrange = grid_y >= 0 && grid_y+4 < grid[grid.size() - 1].size();//竖着是否越界
	//bool iscollision = 
	//	grid[grid_x][grid_y].isfull || 
	//	grid[grid_x][grid_y+1].isfull || 
	//	grid[grid_x][grid_y+2].isfull || 
	//	grid[grid_x][grid_y+3].isfull;//是否发生碰撞
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

void shape1::setFull(int mswitch) {

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

void shape1::rotate(int &block_x,int &block_y,int &swicth) {
	if (getState() == 0)//由横变竖
	{
		std::vector<int>changex = { 2,2,2,2 };//从左到右依次是需要转换的位置，优先级逐步降低
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
	else if (getState() == 1)//由竖变横
	{
		std::vector<int>changex = { -2,-1,-3,0 };//从左到右依次是需要转换的位置，优先级逐步降低
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


/***************************************七字***************************************/
void shape2::CreateBlocks(QPainter &painter, int mswitch)//保证是形状的左上角作画
{
	painter.setRenderHint(QPainter::Antialiasing, true);
	// 设置画笔颜色、宽度
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// 设置画刷颜色
	painter.setBrush(QColor(255, 100, 60));
	switch (mswitch)
	{
	default://默认状态，也就是初始形状
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y + m_hight, m_width, m_hight);
		state = 0;
		break;

	case 1://顺时针旋转90
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight*2, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		state = 1;
		break;
	case 2://顺时针旋转180
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y , m_width, m_hight);
		painter.drawRect(m_x + m_width*2, m_y , m_width, m_hight);
		painter.drawRect(m_x + m_width*2, m_y + m_hight, m_width, m_hight);
		state = 2;
		break;
		
	case 3://顺时针旋转270
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight*2, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight*2, m_width, m_hight);
		state = 3;
		break;
	}
}

bool shape2::isInrange(int mswitch) {

	if (grid.empty())
	{
		return false;
	}
	//bool x_isInrange = grid_x >= 0 && grid_x < grid.size();//x是否越界
	//bool y_isInrange = grid_y >= 0 && grid_y+4 < grid[grid.size() - 1].size();//竖着是否越界
	//bool iscollision = 
	//	grid[grid_x][grid_y].isfull || 
	//	grid[grid_x][grid_y+1].isfull || 
	//	grid[grid_x][grid_y+2].isfull || 
	//	grid[grid_x][grid_y+3].isfull;//是否发生碰撞
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
	}else 
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

}
void shape2::setFull(int mswitch) {

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
	else
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x][grid_y + 2].isfull = true;
		grid[grid_x - 1][grid_y + 2].isfull = true;

	}
}
void shape2::rotate(int &block_x, int &block_y, int &swicth) {
	if (getState() == 0)//由初始顺时针旋转90
	{
		std::vector<int>changex = { 1,0,2,1 };//从左到右依次是需要转换的位置，优先级逐步降低
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
	else if (getState() == 1)//继续旋转90
	{
		std::vector<int>changex = { -1,-2,0 };//从左到右依次是需要转换的位置，优先级逐步降低
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
	else if (getState() == 2)//继续旋转90
	{
		std::vector<int>changex = { 1,0,2 ,1};//从左到右依次是需要转换的位置，优先级逐步降低
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
	else if (getState() == 3)//继续旋转90
	{
		std::vector<int>changex = { -1,-2,1,-1 };//从左到右依次是需要转换的位置，优先级逐步降低
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
}

/***************************************土字***************************************/
void shape3::CreateBlocks(QPainter &painter, int mswitch) {
	painter.setRenderHint(QPainter::Antialiasing, true);
	// 设置画笔颜色、宽度
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// 设置画刷颜色
	painter.setBrush(QColor(150, 100, 60));

	switch (mswitch)
	{
	default://默认状态，也就是初始形状，最上面的方块最为参考点
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		state = 0;
		break;

	case 1://顺时针旋转90 最上面的方块作为参考点
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight * 2, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		state = 1;
		break;
	case 2://顺时针旋转180 最左边的方块作为参考点
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width * 2, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width , m_y + m_hight, m_width, m_hight);
		state = 2;
		break;

	case 3://顺时针旋转270
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight * 2, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
		state = 3;
		break;
	}
}
bool shape3::isInrange(int mswitch) {

	if (grid.empty())
	{
		return false;
	}
	//bool x_isInrange = grid_x >= 0 && grid_x < grid.size();//x是否越界
	//bool y_isInrange = grid_y >= 0 && grid_y+4 < grid[grid.size() - 1].size();//竖着是否越界
	//bool iscollision = 
	//	grid[grid_x][grid_y].isfull || 
	//	grid[grid_x][grid_y+1].isfull || 
	//	grid[grid_x][grid_y+2].isfull || 
	//	grid[grid_x][grid_y+3].isfull;//是否发生碰撞
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
void shape3::setFull(int mswitch) {

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
void shape3::rotate(int &block_x, int &block_y, int &swicth) {
	if (getState() == 0)//由初始顺时针旋转90
	{
		std::vector<int>changex = { 0 };//从左到右依次是需要转换的位置，优先级逐步降低
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
	else if (getState() == 1)//继续旋转90
	{
		std::vector<int>changex = { -1,0 };//从左到右依次是需要转换的位置，优先级逐步降低
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
	else if (getState() == 2)//继续旋转90
	{
		std::vector<int>changex = { 1 };//从左到右依次是需要转换的位置，优先级逐步降低
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
	else if (getState() == 3)//继续旋转90
	{
		std::vector<int>changex = { 0,-1 };//从左到右依次是需要转换的位置，优先级逐步降低
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

/***************************************台阶字***************************************/
void shape4::CreateBlocks(QPainter &painter, int mswitch) {
	painter.setRenderHint(QPainter::Antialiasing, true);
	// 设置画笔颜色、宽度
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// 设置画刷颜色
	painter.setBrush(QColor(100, 201, 201));

	switch (mswitch)
	{
	default://默认状态，也就是初始形状，最上面的方块最为参考点
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight * 2, m_width, m_hight);
		state = 0;
		break;

	case 1://顺时针旋转90 最上面的方块作为参考点
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		state = 1;
		break;
	}

}
bool shape4::isInrange(int mswitch) {

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
	else
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
}

void shape4::setFull(int mswitch) {
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
	else
	{
		grid[grid_x][grid_y].isfull = true;
		grid[grid_x + 1][grid_y].isfull = true;
		grid[grid_x][grid_y + 1].isfull = true;
		grid[grid_x - 1][grid_y + 1].isfull = true;
	}
}

void shape4::rotate(int &block_x, int &block_y, int &swicth) {
	if (getState() == 0)//由初始顺时针旋转90
	{
		std::vector<int>changex = { 1,0 };//从左到右依次是需要转换的位置，优先级逐步降低
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
	else if (getState() == 1)//继续旋转90
	{
		std::vector<int>changex = { -1 };//从左到右依次是需要转换的位置，优先级逐步降低
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
}

/***************************************田字***************************************/
void shape5::CreateBlocks(QPainter &painter, int mswitch) {
	painter.setRenderHint(QPainter::Antialiasing, true);
	// 设置画笔颜色、宽度
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	// 设置画刷颜色
	painter.setBrush(QColor(231, 190, 231));

	switch (mswitch)
	{
	default://默认状态，也就是初始形状，最上面的方块最为参考点
		painter.drawRect(m_x, m_y, m_width, m_hight);
		painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
		painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
		state = 0;
		break;

	//case 1://顺时针旋转90 最上面的方块作为参考点
	//	painter.drawRect(m_x, m_y, m_width, m_hight);
	//	painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);
	//	painter.drawRect(m_x - m_width, m_y + m_hight, m_width, m_hight);
	//	painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
	//	state = 1;
	//	break;
	}

	//painter.drawRect(m_x, m_y, m_width, m_hight);

	////painter.setPen(QPen(QColor(0, 160, 230), 2));
	//// 设置画刷颜色
	////painter.setBrush(QColor(255, 160, 90));
	//painter.drawRect(m_x, m_y + m_hight, m_width, m_hight);

	////painter.setBrush(QColor(255, 160, 90));
	//painter.drawRect(m_x + m_width, m_y, m_width, m_hight);
	//painter.drawRect(m_x + m_width, m_y + m_hight, m_width, m_hight);
}

bool shape5::isInrange(int mswitch) {

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

void shape5::setFull(int mswitch) {
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

void shape5::rotate(int &block_x, int &block_y, int &swicth) {
	if (getState() == 0)//由初始顺时针旋转90
	{
		std::vector<int>changex = { 0};//从左到右依次是需要转换的位置，优先级逐步降低
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
	//else if (getState() == 1)//继续旋转90
	//{
	//	std::vector<int>changex = { -1 };//从左到右依次是需要转换的位置，优先级逐步降低
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


/***************************************创建网格***************************************/
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
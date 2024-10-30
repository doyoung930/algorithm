#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지 도달하기 전에는 계속 실행
	Pos dest = board->GetExitPos();

	Pos front[4] = {

		Pos{-1, 0},		//UP
		Pos{0, -1},		//LEFT
		Pos{1, 0},		//DOWN
		Pos{0, 1},		//RIGHT
	};

	while (pos != dest) {
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir])) {
			// 오른쪽 방향으로 90도 회전.
			_dir = newDir;

			// 앞으로 한 보 전진.
			pos += front[_dir];

			_path.push_back(pos);
		}
		else if (CanGo(pos + front[_dir])) {
			//앞으로 한보 전진.
			pos += front[_dir];
			_path.push_back(pos);
		}
		else {
			// 왼쪽 방향으로 90도 회전
			_dir = (_dir + 1) % DIR_COUNT;
			//switch (_dir) {
			//case DIR_UP:
			//	_dir = DIR_LEFT;
			//	break;
			//case DIR_LEFT:
			//	_dir = DIR_DOWN;
			//	break;
			//case DIR_DOWN:
			//	_dir = DIR_DOWN;
			//	break;
			//case DIR_RIGHT:
			//	_dir = DIR_UP;
			//	break;
			//}
		}
	}
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);

	return tileType == TileType::EMPTY ;
}

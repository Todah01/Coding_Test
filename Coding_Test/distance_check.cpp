#if 0
def solution(places) :
    answer = []
    for green_room in places :
seat_coods = []
Check_correct = True

# Get coodinate of seat from each room
for seat_guide_idx in range(len(green_room)) :
    for seat_info_idx in range(len(green_room[seat_guide_idx])) :
        if green_room[seat_guide_idx][seat_info_idx] == 'P' :
            seat_coods.append([seat_guide_idx, seat_info_idx])

            # Check Manhattan distance
            for idx in range(len(seat_coods)) :
                temp_coods = seat_coods[idx + 1:]
                for seat_cood in temp_coods :
Manhatten_dist = abs(seat_coods[idx][0] - seat_cood[0]) + abs(seat_coods[idx][1] - seat_cood[1])
if Manhatten_dist == 2 :
    for x in range(min(seat_coods[idx][0], seat_cood[0]), max(seat_coods[idx][0], seat_cood[0] + 1)) :
        for y in range(min(seat_coods[idx][1], seat_cood[1]), max(seat_coods[idx][1], seat_cood[1] + 1)) :
            if green_room[x][y] == 'O' :
                Check_correct = False
                break
                elif Manhatten_dist == 1 :
                Check_correct = False
                break

                if Check_correct : answer.append(1)
                else : answer.append(0)

                    return answer
#endif
def find_farthest_points(points):
    n = len(points)
    results = []
    for i in range(n):
        max_dist = -1
        farthest_id = -1
        x1, y1 = points[i]
        for j in range(n):
            if i != j:
                x2, y2 = points[j]
                dist = (x1 - x2)**2 + (y1 - y2)**2
                if dist > max_dist or (dist == max_dist and j + 1 < farthest_id):
                    max_dist = dist
                    farthest_id = j + 1  # Dùng chỉ số bắt đầu từ 1
        results.append(farthest_id)
    return results

# Đoạn này dùng nhập liệu từ bàn phím
if __name__ == "__main__":
    n = int(input())
    points = []
    for _ in range(n):
        x, y = map(int, input().split())
        points.append((x, y))
    results = find_farthest_points(points)
    for res in results:
        print(res)

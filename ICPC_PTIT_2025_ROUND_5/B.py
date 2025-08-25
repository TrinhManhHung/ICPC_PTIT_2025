def solve():
    s = input()
    star_idx = -1

    try:
        star_idx = s.index('*')
    except ValueError:

        print(0)
        return

    stack = []
    pairs = []

    for i, char in enumerate(s):
        if char == '(':
            stack.append(i)
        elif char == ')':
            if stack:

                left_index = stack.pop()

                pairs.append((left_index, i))

    count = 0

    for left, right in pairs:
        if left < star_idx < right:
            count += 1

    print(count)


def main():

    try:
        num_tests = int(input())
        for _ in range(num_tests):
            solve()
    except (IOError, ValueError):

        pass


if __name__ == "__main__":
    main()


def determineWinner(markers):
    james_points = 0
    bob_points = 0

    while len(markers) > 0:
        if len(markers) == 1:
            james_points += markers[0]
            break

        if markers[0] >= markers[-1]:
            james_points += markers[0]
            markers = markers[1:-1]
        else:
            bob_points += markers[-1]
            markers = markers[0:-1]

    return james_points

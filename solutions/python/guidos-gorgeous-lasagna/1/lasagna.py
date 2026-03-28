"""Functions to help cook and bake a lasagna.

This module provides constants and functions to calculate various
cooking times for a perfect lasagna.
"""

# 1. Define the expected bake time constant
EXPECTED_BAKE_TIME = 40
PREPARATION_TIME_PER_LAYER = 2


def bake_time_remaining(elapsed_bake_time):
    """Calculate the remaining bake time.

    :param elapsed_bake_time: int - baking time already spent.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """
    return EXPECTED_BAKE_TIME - elapsed_bake_time


def preparation_time_in_minutes(number_of_layers):
    """Calculate the preparation time.

    :param number_of_layers: int - the number of layers you want to add.
    :return: int - total preparation time (in minutes).

    This function takes the number of layers you want to add to the lasagna
    and calculates the total preparation time based on 2 minutes per layer.
    """
    return number_of_layers * PREPARATION_TIME_PER_LAYER


def elapsed_time_in_minutes(number_of_layers, elapsed_bake_time):
    """Calculate the total elapsed cooking time (prep + bake).

    :param number_of_layers: int - the number of layers in the lasagna.
    :param elapsed_bake_time: int - elapsed baking time.
    :return: int - total time elapsed (in minutes) preparing and cooking.

    This function takes two integers representing the number of lasagna layers and the
    time already spent baking and calculates the total elapsed minutes spent cooking the
    lasagna.
    """
    return preparation_time_in_minutes(number_of_layers) + elapsed_bake_time

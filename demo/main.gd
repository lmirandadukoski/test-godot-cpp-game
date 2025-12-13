extends Node3D

func _ready() -> void:
	var summator = Summator.new()
	summator.add(1)
	summator.add(3)
	print(summator.get_total())

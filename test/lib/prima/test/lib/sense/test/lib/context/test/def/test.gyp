{
	'includes':[
		'../../def/base.gypi',
		'../../plank/def/mac-targets.gypi'
	],#inclues
	'target_defaults': {
		'target_name': 'test',
		'type': 'executable',
		'sources': [
			'../src/context_test.h',
			'../src/observer_test.h',
			'../src/main.cpp',
		], #sources
		'include_dirs': [
			'../../plank/src/',
			'../../'
		], #include_dirs		
	}, #target_defaults
}
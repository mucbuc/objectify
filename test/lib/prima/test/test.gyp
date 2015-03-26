{
	'includes':[
		'lib/context/def.gypi',
		'lib/numbro/def.gypi',
		'lib/static/def.gypi',
		'lib/traverse/def/base.gypi',
		'plank/def/cpp11.gypi',
		'plank/def/mac-targets.gypi',
	],#includes
	'target_defaults': {
		'target_name': 'test', 
		'type': 'executable',
		'sources': [
			'src/main.cpp',
		], #sources
		'include_dirs': [
			'plank/src/',
			'.'
		], #include_dirs		
	}, #target_defaults
}
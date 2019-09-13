struct T : Spec::T
{
	using Value = T;

	using Spec::T::T;

	const GetConfig::Duration::T::Value &
	inputTimeout () const;

	GetConfig::Duration::T::Value &
	inputTimeout ();

	const GetConfig::Duration::T::Value &
	outputTimeout () const;

	GetConfig::Duration::T::Value &
	outputTimeout ();

	const GetConfig::Duration::T::Value &
	roundTripTimeout () const;

	GetConfig::Duration::T::Value &
	roundTripTimeout ();
};
